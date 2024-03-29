// Inheritance: UPlayer > UObject
namespace ULocalPlayer
{
	constexpr auto ViewportClient = 0x78; // UGameViewportClient*
	constexpr auto AspectRatioAxisConstraint = 0x9c; // EAspectRatioAxisConstraint
	constexpr auto PendingLevelPlayerControllerClass = 0xa0; // APlayerController*
	constexpr auto bSentSplitJoin = 0xa8; // char
	constexpr auto ControllerId = 0xc0; // int32_t
}
namespace UWorld
{
	constexpr auto PersistentLevel = 0x38; // ULevel*
	constexpr auto NetDriver = 0x40; // UNetDriver*
	constexpr auto LineBatcher = 0x48; // ULineBatchComponent*
	constexpr auto PersistentLineBatcher = 0x50; // ULineBatchComponent*
	constexpr auto ForegroundLineBatcher = 0x58; // ULineBatchComponent*
	constexpr auto NetworkManager = 0x60; // AGameNetworkManager*
	constexpr auto PhysicsCollisionHandler = 0x68; // UPhysicsCollisionHandler*
	constexpr auto ExtraReferencedObjects = 0x70; // TArray<UObject*>
	constexpr auto PerModuleDataObjects = 0x80; // TArray<UObject*>
	constexpr auto StreamingLevels = 0x90; // TArray<ULevelStreaming*>
	constexpr auto StreamingLevelsToConsider = 0xa0; // FStreamingLevelsToConsider
	constexpr auto StreamingLevelsPrefix = 0xc8; // FString
	constexpr auto CurrentLevelPendingVisibility = 0xd8; // ULevel*
	constexpr auto CurrentLevelPendingInvisibility = 0xe0; // ULevel*
	constexpr auto DemoNetDriver = 0xe8; // UDemoNetDriver*
	constexpr auto MyParticleEventManager = 0xf0; // AParticleEventManager*
	constexpr auto bAresLevelIgnoresZPrepass = 0xf8; // bool
	constexpr auto AresZPrepassMesh = 0x100; // AStaticMeshActor*
	constexpr auto DefaultPhysicsVolume = 0x108; // APhysicsVolume*
	constexpr auto bAreConstraintsDirty = 0x128; // char
	constexpr auto NavigationSystem = 0x130; // UNavigationSystemBase*
	constexpr auto AuthorityGameMode = 0x138; // AGameModeBase*
	constexpr auto GameState = 0x140; // AGameStateBase*
	constexpr auto AISystem = 0x148; // UAISystemBase*
	constexpr auto AvoidanceManager = 0x150; // UAvoidanceManager*
	constexpr auto Levels = 0x158; // TArray<ULevel*>
	constexpr auto LevelCollections = 0x168; // TArray<FLevelCollection>
	constexpr auto OwningGameInstance = 0x1a0; // UGameInstance*
	constexpr auto ParameterCollectionInstances = 0x1a8; // TArray<UMaterialParameterCollectionInstance*>
	constexpr auto CanvasForRenderingToTarget = 0x1b8; // UCanvas*
	constexpr auto CanvasForDrawMaterialToRenderTarget = 0x1c0; // UCanvas*
	constexpr auto ComponentsThatNeedPreEndOfFrameSync = 0x230; // TSet<UActorComponent*>
	constexpr auto ComponentsThatNeedEndOfFrameUpdate = 0x280; // TArray<UActorComponent*>
	constexpr auto ComponentsThatNeedEndOfFrameUpdate_OnGameThread = 0x290; // TArray<UActorComponent*>
	constexpr auto WorldComposition = 0x650; // UWorldComposition*
	constexpr auto bFlushNetConnectionsAfterFirstActorTick = 0x6e8; // bool
	constexpr auto PSCPool = 0x6f0; // FWorldPSCPool
	constexpr auto ParticleDecalManager = 0x810; // FParticleDecalManager
}

// Inheritance: UObject
namespace AActor
{
	constexpr auto PrimaryActorTick = 0x30; // FActorTickFunction
	constexpr auto bLocallyHidden = 0x60; // char
	constexpr auto OnActorHiddenChanged = 0x68; // FMulticastInlineDelegate
	constexpr auto bNetTemporary = 0x11c; // char
	constexpr auto bNetStartup = 0x11c; // char
	constexpr auto bOnlyRelevantToOwner = 0x11c; // char
	constexpr auto bAlwaysRelevant = 0x11c; // char
	constexpr auto bReplicateMovement = 0x11c; // char
	constexpr auto bHidden = 0x11c; // char
	constexpr auto bTearOff = 0x11c; // char
	constexpr auto bExchangedRoles = 0x11c; // char
	constexpr auto bNetLoadOnClient = 0x11d; // char
	constexpr auto bNetUseOwnerRelevancy = 0x11d; // char
	constexpr auto bRelevantForNetworkReplays = 0x11d; // char
	constexpr auto bRelevantForLevelBounds = 0x11d; // char
	constexpr auto bReplayRewindable = 0x11d; // char
	constexpr auto bAllowTickBeforeBeginPlay = 0x11d; // char
	constexpr auto bAutoDestroyWhenFinished = 0x11d; // char
	constexpr auto bCanBeDamaged = 0x11d; // char
	constexpr auto bBlockInput = 0x11e; // char
	constexpr auto bCollideWhenPlacing = 0x11e; // char
	constexpr auto bFindCameraComponentWhenViewTarget = 0x11e; // char
	constexpr auto bGenerateOverlapEventsDuringLevelStreaming = 0x11e; // char
	constexpr auto bIgnoresOriginShifting = 0x11e; // char
	constexpr auto bEnableAutoLODGeneration = 0x11e; // char
	constexpr auto bIsEditorOnlyActor = 0x11e; // char
	constexpr auto bActorSeamlessTraveled = 0x11e; // char
	constexpr auto bReplicates = 0x11f; // char
	constexpr auto bCanBeInCluster = 0x11f; // char
	constexpr auto bAllowReceiveTickEventOnDedicatedServer = 0x11f; // char
	constexpr auto bActorEnableCollision = 0x120; // char
	constexpr auto bActorIsBeingDestroyed = 0x120; // char
	constexpr auto UpdateOverlapsMethodDuringLevelStreaming = 0x121; // EActorUpdateOverlapsMethod
	constexpr auto DefaultUpdateOverlapsMethodDuringLevelStreaming = 0x122; // EActorUpdateOverlapsMethod
	constexpr auto RemoteRole = 0x123; // ENetRole
	constexpr auto ReplicatedMovement = 0x124; // FRepMovement
	constexpr auto InitialLifeSpan = 0x16c; // float
	constexpr auto CustomTimeDilation = 0x170; // float
	constexpr auto AttachmentReplication = 0x178; // FRepAttachment
	constexpr auto Owner = 0x1b8; // AActor*
	constexpr auto NetDriverName = 0x1c0; // FName
	constexpr auto Role = 0x1cc; // ENetRole
	constexpr auto NetDormancy = 0x1cd; // ENetDormancy
	constexpr auto SpawnCollisionHandlingMethod = 0x1ce; // ESpawnActorCollisionHandlingMethod
	constexpr auto AutoReceiveInput = 0x1cf; // EAutoReceiveInput
	constexpr auto InputPriority = 0x1d0; // int32_t
	constexpr auto InputComponent = 0x1d8; // UInputComponent*
	constexpr auto NetCullDistanceSquared = 0x1e0; // float
	constexpr auto NetTag = 0x1e4; // int32_t
	constexpr auto NetUpdateFrequency = 0x1e8; // float
	constexpr auto MinNetUpdateFrequency = 0x1ec; // float
	constexpr auto NetPriority = 0x1f0; // float
	constexpr auto Instigator = 0x218; // APawn*
	constexpr auto Children = 0x220; // TArray<AActor*>
	constexpr auto RootComponent = 0x230; // USceneComponent*
	constexpr auto ControllingMatineeActors = 0x238; // TArray<AMatineeActor*>
	constexpr auto TimerHandle_LifeSpanExpired = 0x248; // FTimerHandle
	constexpr auto Layers = 0x250; // TArray<FName>
	constexpr auto ParentComponent = 0x260; // TWeakObjectPtr<UChildActorComponent>
	constexpr auto Tags = 0x270; // TArray<FName>
	constexpr auto OnTakeAnyDamage = 0x280; // FMulticastSparseDelegate
	constexpr auto OnTakePointDamage = 0x281; // FMulticastSparseDelegate
	constexpr auto OnTakeRadialDamage = 0x282; // FMulticastSparseDelegate
	constexpr auto OnActorBeginOverlap = 0x283; // FMulticastSparseDelegate
	constexpr auto OnActorEndOverlap = 0x284; // FMulticastSparseDelegate
	constexpr auto OnBeginCursorOver = 0x285; // FMulticastSparseDelegate
	constexpr auto OnEndCursorOver = 0x286; // FMulticastSparseDelegate
	constexpr auto OnClicked = 0x287; // FMulticastSparseDelegate
	constexpr auto OnReleased = 0x288; // FMulticastSparseDelegate
	constexpr auto OnInputTouchBegin = 0x289; // FMulticastSparseDelegate
	constexpr auto OnInputTouchEnd = 0x28a; // FMulticastSparseDelegate
	constexpr auto OnInputTouchEnter = 0x28b; // FMulticastSparseDelegate
	constexpr auto OnInputTouchLeave = 0x28c; // FMulticastSparseDelegate
	constexpr auto OnActorHit = 0x28d; // FMulticastSparseDelegate
	constexpr auto PostActorBeginPlay = 0x290; // FMulticastInlineDelegate
	constexpr auto OnDestroyed = 0x2a0; // FMulticastSparseDelegate
	constexpr auto OnEndPlay = 0x2a1; // FMulticastSparseDelegate
	constexpr auto OnForceNetUpdate = 0x2a8; // FMulticastInlineDelegate
	constexpr auto OnClientRoleChanged = 0x2b8; // FMulticastInlineDelegate
	constexpr auto InstanceComponents = 0x3a0; // TArray<UActorComponent*>
	constexpr auto BlueprintCreatedComponents = 0x3b0; // TArray<UActorComponent*>
}

// Inheritance: AActor > UObject
namespace AController
{
	constexpr auto PlayerState = 0x3d8; // APlayerState*
	constexpr auto OnInstigatedAnyDamage = 0x3e8; // FMulticastInlineDelegate
	constexpr auto StateName = 0x3f8; // FName
	constexpr auto Pawn = 0x408; // APawn*
	constexpr auto Character = 0x418; // ACharacter*
	constexpr auto TransformComponent = 0x420; // USceneComponent*
	constexpr auto ControlRotation = 0x440; // FRotator
	constexpr auto bAttachToPawn = 0x44c; // char
}

// Inheritance: AController > AActor > UObject
namespace APlayerController
{
	constexpr auto Player = 0x458; // UPlayer*
	constexpr auto AcknowledgedPawn = 0x460; // APawn*
	constexpr auto ControllingDirTrackInst = 0x468; // UInterpTrackInstDirector*
	constexpr auto MyHUD = 0x470; // AHUD*
	constexpr auto PlayerCameraManager = 0x478; // APlayerCameraManager*
	constexpr auto PlayerCameraManagerClass = 0x480; // APlayerCameraManager*
	constexpr auto bAutoManageActiveCameraTarget = 0x488; // bool
	constexpr auto HiddenActors = 0x490; // TArray<AActor*>
	constexpr auto HiddenPrimitiveComponents = 0x4a0; // TArray<TWeakObjectPtr<UPrimitiveComponent>>
	constexpr auto LastSpectatorStateSynchTime = 0x4b4; // float
	constexpr auto LastSpectatorSyncLocation = 0x4b8; // FVector
	constexpr auto LastSpectatorSyncRotation = 0x4c4; // FRotator
	constexpr auto ClientCap = 0x4d0; // int32_t
	constexpr auto CheatManager = 0x4d8; // UCheatManager*
	constexpr auto CheatClass = 0x4e0; // UCheatManager*
	constexpr auto PlayerInput = 0x4e8; // UPlayerInput*
	constexpr auto ActiveForceFeedbackEffects = 0x4f0; // TArray<FActiveForceFeedbackEffect>
	constexpr auto OnCinematicModeUpdated = 0x578; // FMulticastInlineDelegate
	constexpr auto bPlayerIsWaiting = 0x588; // char
	constexpr auto NetPlayerIndex = 0x58c; // char
	constexpr auto PendingSwapConnection = 0x5c8; // UNetConnection*
	constexpr auto NetConnection = 0x5d0; // UNetConnection*
	constexpr auto InputYawScale = 0x5e4; // float
	constexpr auto InputPitchScale = 0x5e8; // float
	constexpr auto InputRollScale = 0x5ec; // float
	constexpr auto bShowMouseCursor = 0x5f0; // char
	constexpr auto bEnableClickEvents = 0x5f0; // char
	constexpr auto bEnableTouchEvents = 0x5f0; // char
	constexpr auto bEnableMouseOverEvents = 0x5f0; // char
	constexpr auto bEnableTouchOverEvents = 0x5f0; // char
	constexpr auto bForceFeedbackEnabled = 0x5f0; // char
	constexpr auto ForceFeedbackScale = 0x5f4; // float
	constexpr auto ClickEventKeys = 0x5f8; // TArray<FKey>
	constexpr auto DefaultMouseCursor = 0x608; // EMouseCursor
	constexpr auto CurrentMouseCursor = 0x609; // EMouseCursor
	constexpr auto DefaultClickTraceChannel = 0x60a; // ECollisionChannel
	constexpr auto CurrentClickTraceChannel = 0x60b; // ECollisionChannel
	constexpr auto HitResultTraceDistance = 0x60c; // float
	constexpr auto SeamlessTravelCount = 0x610; // uint16_t
	constexpr auto LastCompletedSeamlessTravelCount = 0x612; // uint16_t
	constexpr auto InactiveStateInputComponent = 0x688; // UInputComponent*
	constexpr auto bShouldPerformFullTickWhenPaused = 0x690; // char
	constexpr auto CurrentTouchInterface = 0x6a8; // UTouchInterface*
	constexpr auto SpectatorPawn = 0x700; // ASpectatorPawn*
	constexpr auto bIsLocalPlayerController = 0x70c; // bool
	constexpr auto SpawnLocation = 0x710; // FVector
}

// Inheritance: UObject
namespace UActorComponent
{
	constexpr auto PrimaryComponentTick = 0x48; // FActorComponentTickFunction
	constexpr auto ComponentTags = 0x78; // TArray<FName>
	constexpr auto AssetUserData = 0x88; // TArray<UAssetUserData*>
	constexpr auto UCSSerializationIndex = 0x9c; // int32_t
	constexpr auto bNetAddressable = 0xa0; // char
	constexpr auto bReplicates = 0xa0; // char
	constexpr auto TickTimingsAccumulatedTotal = 0xa8; // uint64_t
	constexpr auto TickTimingsAccumulatedBP = 0xb0; // uint64_t
	constexpr auto TickTimingsStart = 0xb8; // uint64_t
	constexpr auto bAutoActivate = 0xc1; // char
	constexpr auto bIsActive = 0xc1; // char
	constexpr auto bEditableWhenInherited = 0xc1; // char
	constexpr auto bCanEverAffectNavigation = 0xc1; // char
	constexpr auto bIsEditorOnly = 0xc2; // char
	constexpr auto CreationMethod = 0xc4; // EComponentCreationMethod
	constexpr auto OnComponentActivated = 0xc5; // FMulticastSparseDelegate
	constexpr auto OnComponentDeactivated = 0xc6; // FMulticastSparseDelegate
	constexpr auto UCSModifiedProperties = 0xc8; // TArray<FSimpleMemberReference>
}

namespace AAresEquippable
{
	constexpr auto EquippableTickState = 0x450; // EEquippableTickState
	constexpr auto ObjectiveIcon = 0x4f8; // UTexture*
	constexpr auto bUsingCharacterAlternateAnims = 0x500; // bool
	constexpr auto CharacterAnims1P = 0x508; // TMap<UAnimSlot1P*, TSoftObjectPtr<UAnimationAsset>>
	constexpr auto CharacterAnimsAltmode1P = 0x558; // TMap<UAnimSlot1P*, TSoftObjectPtr<UAnimationAsset>>
	constexpr auto CharacterAnimsAltmode1POverride = 0x5a8; // TMap<UAnimSlot1P*, TSoftObjectPtr<UAnimationAsset>>
	constexpr auto CharacterAnims1POverride = 0x5f8; // TMap<UAnimSlot1P*, TSoftObjectPtr<UAnimationAsset>>
	constexpr auto GunAnims1POverride = 0x648; // TMap<UAnimSlotGun1P*, TSoftObjectPtr<UAnimationAsset>>
	constexpr auto CosmeticGunAnims1POverride = 0x698; // TMap<UAnimSlotGun1P*, TSoftObjectPtr<UAnimationAsset>>
	constexpr auto CosmeticGunAnimsAltmode1POverride = 0x6e8; // TMap<UAnimSlotGun1P*, TSoftObjectPtr<UAnimationAsset>>
	constexpr auto CharacterAnimsLowerBody3POverride = 0x738; // TMap<UAnimSlotLowerBody3P*, UAnimationAsset*>
	constexpr auto CharacterAnimsUpperBody3POverride = 0x788; // TMap<UAnimSlotUpperBody3P*, UAnimationAsset*>
	constexpr auto GunAnims1P = 0x7d8; // TMap<UAnimSlotGun1P*, TSoftObjectPtr<UAnimationAsset>>
	constexpr auto CharacterAnimsUpperBody3P = 0x828; // TMap<UAnimSlotUpperBody3P*, UAnimationAsset*>
	constexpr auto CharacterAnimsAltModeUpperBody3P = 0x878; // TMap<UAnimSlotUpperBody3P*, UAnimationAsset*>
	constexpr auto CharacterAnimsLowerBody3P = 0x8c8; // TMap<UAnimSlotLowerBody3P*, UAnimationAsset*>
	constexpr auto CharacterAnimsAltModeLowerBody3P = 0x918; // TMap<UAnimSlotLowerBody3P*, UAnimationAsset*>
	constexpr auto CharacterAnimsFace3P = 0x968; // TMap<UAnimSlotFace3P*, UAnimationAsset*>
	constexpr auto CharacterAnimsAltModeFace3P = 0x9b8; // TMap<UAnimSlotFace3P*, UAnimationAsset*>
	constexpr auto LeftHandIKEnabled = 0xa08; // bool
	constexpr auto RightHandIKEnabled = 0xa09; // bool
	constexpr auto AltModeLeftHandIKEnabled = 0xa0a; // bool
	constexpr auto AltModeRightHandIKEnabled = 0xa0b; // bool
	constexpr auto InaccuracyAnimationMultiplier = 0xa0c; // float
	constexpr auto AimOffsetDisableOnEquip = 0xa10; // float
	constexpr auto PrimaryAimSpring1PStiffness = 0xa14; // float
	constexpr auto PrimaryAimSpring1PDampening = 0xa18; // float
	constexpr auto SecondaryAimSpring1PStiffness = 0xa1c; // float
	constexpr auto SecondaryAimSpring1PDampening = 0xa20; // float
	constexpr auto PickupSoundEvent = 0xa28; // UAkAudioEvent*
	constexpr auto OnRejectedInput = 0xa30; // FMulticastInlineDelegate
	constexpr auto AimToolingModifiers = 0xa40; // FEquippableAimToolingModifiers
	constexpr auto CachedCharacterAnimationAssetMap = 0xa68; // TMap<UAnimSlot1P*, FAsyncLoadedEquippableCharacterAnim>
	constexpr auto CachedGunAnimationAssetMap = 0xab8; // TMap<UAnimSlotGun1P*, FAsyncLoadedEquippableGunAnim>
	constexpr auto AttributeOwner = 0xb08; // TWeakObjectPtr<AShooterCharacter>
	constexpr auto OnItemEquipped = 0xb10; // FMulticastInlineDelegate
	constexpr auto OnItemUnequipped = 0xb20; // FMulticastInlineDelegate
	constexpr auto EquipQueueTime = 0xb48; // float
	constexpr auto bCanBeAutoEquipped = 0xb4c; // bool
	constexpr auto bCanBeAutoEquippedWithoutResources = 0xb4d; // bool
	constexpr auto bCanBeEquippedOutsideGameplay = 0xb4e; // bool
	constexpr auto EquippableOnSetOwner = 0xb50; // FMulticastInlineDelegate
	constexpr auto SuppressionBehavior = 0xb60; // EEquippableSuppressionBehavior
	constexpr auto EquipBehavior = 0xb61; // EEquippableEquipBehavior
	constexpr auto OverrideHolstering = 0xb62; // bool
	constexpr auto OnMeshVisibilityUpdated = 0xb68; // FMulticastInlineDelegate
	constexpr auto PostInitErrors = 0xb78; // TArray<FString>
	constexpr auto EffectOverrides = 0xb88; // TMap<TSoftClassPtr<UObject>, AEffectContainer*>
	constexpr auto ZoomManager = 0xbd8; // UZoomManagerComponent*
	constexpr auto bAutoEquip = 0xbe1; // bool
	constexpr auto bAutoPickup = 0xbe2; // bool
	constexpr auto AutoPickupDistance = 0xbe4; // float
	constexpr auto PreventPickupDuration = 0xbe8; // float
	constexpr auto ScaleOnGround = 0xbec; // float
	constexpr auto bResetMyRoot3PScaleWhenDroppedOnGround = 0xbf0; // bool
	constexpr auto FootstepEvent = 0xbf8; // UAkAudioEvent*
	constexpr auto JumpEvent = 0xc00; // UAkAudioEvent*
	constexpr auto LandEvent = 0xc08; // UAkAudioEvent*
	constexpr auto CooldownComponent = 0xc10; // UCooldownComponent*
	constexpr auto OnDisabledInputRequested = 0xc18; // FMulticastInlineDelegate
	constexpr auto OnEquippableDisabled = 0xc28; // FMulticastInlineDelegate
	constexpr auto bDestroyWhenDropped = 0xc38; // bool
	constexpr auto OnDropped = 0xc40; // FMulticastInlineDelegate
	constexpr auto OnFiringVFXStateUpdated = 0xc50; // FMulticastInlineDelegate
	constexpr auto OnEquippableVFXStateChanged = 0xc60; // FMulticastInlineDelegate
	constexpr auto OnEquippableZoomVFXStateChanged = 0xc70; // FMulticastInlineDelegate
	constexpr auto bInPersistentData = 0xc80; // bool
	constexpr auto bCanActivateWhenSlotDisabled = 0xc81; // bool
	constexpr auto bHideFirstPersonWhileZoomed = 0xc82; // bool
	constexpr auto ZoomInHideOption = 0xc83; // EZoomInHideOption
	constexpr auto ZoomOutShowOption = 0xc84; // EZoomOutShowOption
	constexpr auto ZoomedMovementRatio = 0xc88; // float
	constexpr auto AlwaysTurnRatio = 0xc8c; // float
	constexpr auto AlwaysMovementRatio = 0xc90; // float
	constexpr auto EquippableAttachPoint1P = 0xc94; // FName
	constexpr auto EquippableAttachPoint3P = 0xca0; // FName
	constexpr auto MySceneRoot = 0xcb0; // USceneComponent*
	constexpr auto MyRoot3P = 0xcb8; // USceneComponent*
	constexpr auto Mesh1P = 0xcc0; // USkeletalMeshComponent*
	constexpr auto OutlineComponent1P = 0xcc8; // UAresOutlineComponent*
	constexpr auto Mesh3P = 0xcd0; // USkeletalMeshComponent*
	constexpr auto OutlineComponent3P = 0xcd8; // UAresOutlineComponent*
	constexpr auto EquippableStateMachine = 0xce0; // UEquippableStateMachineComponent*
	constexpr auto CurrentEquippableVFXState = 0xce8; // EAresEquippableState
	constexpr auto EquippableFogOfWar = 0xcf0; // UEquippableFogOfWarComponent*
	constexpr auto EquippableEventComponent = 0xcf8; // UEquippableEventEquippableComponent*
	constexpr auto EquippableCycleZoomState = 0xd00; // UCycleZoomState*
	constexpr auto EquippableStateMachines = 0xd08; // TArray<UEquippableStateMachineComponent*>
	constexpr auto Meshes = 0xd18; // TArray<USkeletalMeshComponent*>
	constexpr auto InventoryAttachPoint = 0xd28; // FName
	constexpr auto bCanBeDropped = 0xd34; // bool
	constexpr auto bDropOnDeath = 0xd35; // bool
	constexpr auto DropOnDeathNew = 0xd36; // EAresDropOnDeath
	constexpr auto DropOnDeathScatterMin = 0xd38; // FRotator
	constexpr auto DropOnDeathScatterMax = 0xd44; // FRotator
	constexpr auto bOnlyAlliesCanPickup = 0xd50; // bool
	constexpr auto PickupPriority = 0xd51; // EUsablePriority
	constexpr auto PickupScoringBonus = 0xd54; // float
	constexpr auto MuzzlePointSocketName = 0xd58; // FName
	constexpr auto SkinKillBannerData = 0xda8; // UKillBannerData*
	constexpr auto InventoryIcon = 0xdb0; // UTexture*
	constexpr auto SkinDataAsset = 0xdb8; // UEquippableSkinDataAsset*
	constexpr auto SkinLevelDataAsset = 0xdc0; // UEquippableSkinLevelDataAsset*
	constexpr auto AttachmentDataAssets = 0xdc8; // TArray<UEquippableAttachmentDataAsset*>
	constexpr auto ChromaDataAsset = 0xdd8; // UEquippableSkinChromaDataAsset*
	constexpr auto CharmDataAsset = 0xde0; // UEquippableCharmDataAsset*
	constexpr auto CharmLevelDataAsset = 0xde8; // UEquippableCharmLevelDataAsset*
	constexpr auto SkinDataAssetId = 0xdf0; // FGuid
	constexpr auto SkinLevelDataAssetId = 0xe00; // FGuid
	constexpr auto CharmDataAssetId = 0xe10; // FGuid
	constexpr auto CharmLevelDataAssetId = 0xe20; // FGuid
	constexpr auto AttachmentDataAssetIds = 0xe30; // TArray<FGuid>
	constexpr auto ChromaDataAssetId = 0xe40; // FGuid
	constexpr auto PreventPickupCharacter = 0xe50; // AShooterCharacter*
	constexpr auto CosmeticRandomSeed = 0xe58; // int32_t
	constexpr auto bInitialCooldownOnRoundStart = 0xe68; // bool
	constexpr auto bAuthIsGhostEquipped = 0xe69; // bool
	constexpr auto UnequippedInputs = 0xe70; // TSet<EAresEquippableInput>
	constexpr auto MaxCharges = 0xec0; // int32_t
	constexpr auto ChargesGainedEachRefresh = 0xec4; // int32_t
	constexpr auto AuthHitRegistrationSubTickMovementTimestamp = 0xec8; // float
	constexpr auto AuthServerSnapshottedMovementTimestamp = 0xecc; // float
	constexpr auto bCanAddToStorageSlot = 0xed0; // bool
	constexpr auto HolsterBlockingObjects = 0xed8; // TArray<TWeakObjectPtr<UObject>>
	constexpr auto LastFiringCharacter = 0xee8; // AShooterCharacter*
	constexpr auto bIsForced1PTextureStreamingEnabled = 0xef0; // bool
}

// Inheritance: UActorComponent > UObject
namespace UAresInventory
{
	constexpr auto DropOffset = 0xf0; // FVector
	constexpr auto AuthOnInventoryTransaction = 0x100; // FMulticastInlineDelegate
	constexpr auto OnEquippableEquipped = 0x110; // FMulticastInlineDelegate
	constexpr auto OnEquippableUnequipped = 0x120; // FMulticastInlineDelegate
	constexpr auto OnEquippableChanged = 0x130; // FMulticastInlineDelegate
	constexpr auto OnEquippableRestrictionError = 0x140; // FMulticastInlineDelegate
	constexpr auto OnItemsChanged = 0x150; // FMulticastInlineDelegate
	constexpr auto OnAuthTryPickup = 0x160; // FMulticastInlineDelegate
	constexpr auto ItemSlots = 0x188; // UItemSlot*
	constexpr auto ItemsTrashedThisRound = 0x208; // TArray<AAresItem*>
	constexpr auto LastEquippables = 0x218; // TArray<AAresEquippable*>
	constexpr auto LatestDesiredEquippableSlot = 0x228; // EAresItemSlot
	constexpr auto DesiredEquippable = 0x230; // AAresEquippable*
	constexpr auto PreviousDesiredEquippable = 0x238; // AAresEquippable*
	constexpr auto CurrentEquippable = 0x240; // AAresEquippable*
	constexpr auto bInitialEquippableChanged = 0x248; // bool
	constexpr auto EquippableChange = 0x260; // FPendingEquippableChange
	constexpr auto PendingEquippableChanges = 0x278; // TArray<FPendingEquippableChange>
	constexpr auto DesiredEquippableStartTime = 0x288; // float
	constexpr auto LastCycleEquippableTimestamp = 0x28c; // float
	constexpr auto SlotModifiers = 0x290; // TArray<USlotModifierComponent*>
	constexpr auto ShooterCharacterOwner = 0x2a0; // AShooterCharacter*
	constexpr auto OwningClientCurrentCorrectionIndex = 0x2a8; // int32_t
	constexpr auto AuthCorrectionState = 0x2ac; // EServerCorrectionState
	constexpr auto DisagreementTimeStamp = 0x2b0; // float
	constexpr auto LastPendingReplicationWarning = 0x2b4; // float
	constexpr auto DisagreementGracePeriodDuration = 0x2b8; // float
	constexpr auto bInitialServerCorrectionSent = 0x2bc; // bool
	constexpr auto bInitialServerCorrectionProcessed = 0x2bd; // bool
	constexpr auto bNeedsEquipWeaponAfterRespawn = 0x2c0; // float
	constexpr auto bIsReplacingEquippableWithPickup = 0x2c4; // bool
	constexpr auto AuthServerCorrectRepVariables = 0x2d0; // FInventoryServerCorrectRepVariables
	constexpr auto EquipDebugRecordHistory = 0x2e0; // TArray<FEquipDebugRecord>
	constexpr auto DroppedItems = 0x2f0; // TArray<AAresItem*>
	constexpr auto CycleEquippableSlotOverride = 0x300; // EAresItemSlot
	constexpr auto bIsSuppressible = 0x301; // bool
	constexpr auto SuppressedUnequipSpeed = 0x302; // EEquipSpeed
	constexpr auto StorageClashBehavior = 0x303; // EStorageClashBehavior
}

// Inheritance: AActor > UObject
namespace AAresItem
{
	constexpr auto MaximumAmount = 0x3d0; // int32_t
	constexpr auto AuthItemOnSetOwner = 0x3d8; // FMulticastInlineDelegate
	constexpr auto ItemOnSetOwner = 0x3e8; // FMulticastInlineDelegate
	constexpr auto Persistence = 0x3f8; // URoundPersistenceComponent*
	constexpr auto ReplicationSleepComponent = 0x400; // UReplicationSleepComponent*
	constexpr auto EquippableSlot = 0x408; // EAresItemSlot
	constexpr auto bShouldShowInStore = 0x409; // bool
	constexpr auto MyPawn = 0x410; // AShooterCharacter*
	constexpr auto InInventory = 0x418; // EEquippableInInventory
	constexpr auto AuthOriginalOwnerId = 0x420; // FString
	constexpr auto CachedDataAsset = 0x430; // TWeakObjectPtr<UAresBasePrimaryDataAsset>
	constexpr auto CachedUIData = 0x438; // TWeakObjectPtr<UBaseContentUIData>
}

// Inheritance: UActorComponent > UObject
namespace UAresInventory
{
	constexpr auto DropOffset = 0xf0; // FVector
	constexpr auto AuthOnInventoryTransaction = 0x100; // FMulticastInlineDelegate
	constexpr auto OnEquippableEquipped = 0x110; // FMulticastInlineDelegate
	constexpr auto OnEquippableUnequipped = 0x120; // FMulticastInlineDelegate
	constexpr auto OnEquippableChanged = 0x130; // FMulticastInlineDelegate
	constexpr auto OnEquippableRestrictionError = 0x140; // FMulticastInlineDelegate
	constexpr auto OnItemsChanged = 0x150; // FMulticastInlineDelegate
	constexpr auto OnAuthTryPickup = 0x160; // FMulticastInlineDelegate
	constexpr auto ItemSlots = 0x188; // UItemSlot*
	constexpr auto ItemsTrashedThisRound = 0x208; // TArray<AAresItem*>
	constexpr auto LastEquippables = 0x218; // TArray<AAresEquippable*>
	constexpr auto LatestDesiredEquippableSlot = 0x228; // EAresItemSlot
	constexpr auto DesiredEquippable = 0x230; // AAresEquippable*
	constexpr auto PreviousDesiredEquippable = 0x238; // AAresEquippable*
	constexpr auto CurrentEquippable = 0x240; // AAresEquippable*
	constexpr auto bInitialEquippableChanged = 0x248; // bool
	constexpr auto EquippableChange = 0x260; // FPendingEquippableChange
	constexpr auto PendingEquippableChanges = 0x278; // TArray<FPendingEquippableChange>
	constexpr auto DesiredEquippableStartTime = 0x288; // float
	constexpr auto LastCycleEquippableTimestamp = 0x28c; // float
	constexpr auto SlotModifiers = 0x290; // TArray<USlotModifierComponent*>
	constexpr auto ShooterCharacterOwner = 0x2a0; // AShooterCharacter*
	constexpr auto OwningClientCurrentCorrectionIndex = 0x2a8; // int32_t
	constexpr auto AuthCorrectionState = 0x2ac; // EServerCorrectionState
	constexpr auto DisagreementTimeStamp = 0x2b0; // float
	constexpr auto LastPendingReplicationWarning = 0x2b4; // float
	constexpr auto DisagreementGracePeriodDuration = 0x2b8; // float
	constexpr auto bInitialServerCorrectionSent = 0x2bc; // bool
	constexpr auto bInitialServerCorrectionProcessed = 0x2bd; // bool
	constexpr auto bNeedsEquipWeaponAfterRespawn = 0x2c0; // float
	constexpr auto bIsReplacingEquippableWithPickup = 0x2c4; // bool
	constexpr auto AuthServerCorrectRepVariables = 0x2d0; // FInventoryServerCorrectRepVariables
	constexpr auto EquipDebugRecordHistory = 0x2e0; // TArray<FEquipDebugRecord>
	constexpr auto DroppedItems = 0x2f0; // TArray<AAresItem*>
	constexpr auto CycleEquippableSlotOverride = 0x300; // EAresItemSlot
	constexpr auto bIsSuppressible = 0x301; // bool
	constexpr auto SuppressedUnequipSpeed = 0x302; // EEquipSpeed
	constexpr auto StorageClashBehavior = 0x303; // EStorageClashBehavior
}