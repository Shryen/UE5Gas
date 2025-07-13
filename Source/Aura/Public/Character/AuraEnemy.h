

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Interface/EnemyInterface.h"
#include "CharacterClassInfo.h"
#include "AuraEnemy.generated.h"

struct FGameplayTag;
class UWidgetComponent;
class UAuraUserWidget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewValue);

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public ABaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();

	/** Enemy Interface **/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** End Enemy Interface **/
	
	void BindCallbacks();

	UFUNCTION()
	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);
	
	UPROPERTY(BlueprintReadOnly, Category="Combat")
	bool bHitReact = false;

	UPROPERTY(BlueprintReadOnly, Category="Combat")
	float BaseWalkSpeed = 250.f;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	virtual void InitializeDefaultAttributes() const override;
	/** Combat Interface **/
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface **/

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChanged OnMaxHealthChanged;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBarWidgetComponent;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TObjectPtr<UAuraUserWidget> HealthBarWidget;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> HitReactEffect;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Defaults", meta=(AllowPrivateAccess=true))
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Defaults", meta=(AllowPrivateAccess=true))
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	void SetWidgetController();
	
};
