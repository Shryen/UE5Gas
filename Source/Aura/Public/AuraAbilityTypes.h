#pragma once
#include "GameplayEffectTypes.h"
#include "AuraAbilityTypes.generated.h"


USTRUCT(BlueprintType)
struct FAuraGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()

public:
	
	virtual UScriptStruct* GetScriptStruct() const override { return StaticStruct(); }
	virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess) override;
	
	uint8 IsCriticalHit() const { return bIsCriticalHit; }
	uint8 IsBlockedHit() const { return bIsBlockedHit; }
	void SetIsCriticalHit(bool bInCriticalHit) { bIsCriticalHit = bInCriticalHit; }
	void SetIsBlockedHit(bool bInBlockedHit) { bIsBlockedHit = bInBlockedHit; }
protected:
	UPROPERTY()
	uint8 bIsBlockedHit:1 = false;
	UPROPERTY()
	uint8 bIsCriticalHit:1 = false;


};
