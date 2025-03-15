#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	// Typical parameters for top-down game
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character rotates with controller
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f); // Speed of Rotation
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}
