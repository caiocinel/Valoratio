#pragma once
#include <cstdint>
#include <stdio.h>
#include <string>
#include <random>
#include "settings.h"
#include "thirdparty/driver.h"

namespace fptr_data
{


	enum class kernel_opr : uint32_t
	{
		read = 1,
		write = 2,
		get_process_module = 3,
		get_process_base = 4,
		get_guarded_base = 9,
		unhook_driver = 5,


		alloc,
		free,
		protect
	};


	enum class kernel_err : uint16_t
	{
		invalid_process = 2,
		check_fail,
		no_operation,
		invalid_data,

		no_error = 0,
		unset_err = 1
	};

	struct kernel_com
	{
		int request_key;
		bool success;
		kernel_err error;


		uint32_t target_pid;
		uint32_t user_pid;

		uintptr_t address;
		uintptr_t buffer;

		union
		{
			size_t size;
			const char* name;
		};

		size_t transfer;
	};
}
namespace kernel
{
	class driver
	{
	public:
		driver();
		~driver();

	public:
		uint32_t pid;
		uintptr_t VirtualAddress;
		void attach(uint32_t pid) { this->pid = pid; }
		bool init();

		bool IsGuarded2(uintptr_t pointer)
		{
			constexpr uintptr_t filter = 0xFFFFFFF000000000;
			uintptr_t result = pointer & filter;
			return result == 0x8000000000 || result == 0x10000000000;
		}
		uint64_t ValidatePtr2(uint64_t address)
		{
			if (IsGuarded2(address)) {
				return VirtualAddress + (address & 0xFFFFFF);
			}
			else {
				return address;
			}
		}
		void unload();

		uintptr_t get_process_module(const char* name);
		uintptr_t get_process_base(uint32_t _pid = 0);
		uintptr_t get_guarded_base();
		bool read_buffer(uintptr_t addr, uint8_t* buffer, size_t size, size_t* transfer = nullptr);
		bool write_buffer(uintptr_t addr, uint8_t* buffer, size_t size, size_t* transfer = nullptr);

		template<typename Value_T>
		Value_T read(uintptr_t addr)
		{
			Value_T val;
			if (!this->read_buffer(addr, (uint8_t*)&val, sizeof(Value_T)))
				memset((void*)&val, 0, sizeof(val));
			return val;
		}
		template<typename Value_T>
		Value_T read2(uintptr_t addr)
		{
			Value_T val;
			if (!this->read_buffer(addr, (uint8_t*)&val, sizeof(Value_T)))
				memset((void*)&val, 0, sizeof(val));
			if (IsGuarded2(val))
			{
				val = ValidatePtr2(val);
			}
			return val;
		}
		template<typename Value_T>
		void write(uintptr_t addr, Value_T val) { this->write_buffer(addr, (uint8_t*)&val, sizeof(Value_T)); }
	};
}