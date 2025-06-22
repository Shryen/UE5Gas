#include "AbilitySystem/AbilityTasks/TargetDataUnderMouse.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "GameFramework/GameSession.h"
#include "Player/AuraPlayerController.h"

UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse::Activate()
{
	APlayerController* PC = Ability->GetCurrentActorInfo()->PlayerController.Get();
	FHitResult CursorHit;
	PC->GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if(CursorHit.bBlockingHit)
	{	
		ValidData.Broadcast(CursorHit.ImpactPoint);
	}
}
