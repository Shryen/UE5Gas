

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Interface/EnemyInterface.h"
#include "AuraEnemy.generated.h"

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
	void BindCallbacks() const;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

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

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Defaults", meta=(AllowPrivateAccess=true))
	int32 Level = 1;

	void SetWidgetController();
	
};
