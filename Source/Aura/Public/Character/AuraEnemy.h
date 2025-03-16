

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Interface/EnemyInterface.h"
#include "AuraEnemy.generated.h"

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

protected:
	virtual void BeginPlay() override;
};
