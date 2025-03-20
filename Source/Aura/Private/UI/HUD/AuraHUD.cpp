#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverLayWidgetController(const FWidgetControllerParams& WCParams)
{
	// If not created already create then return
	if(OverlayWidgetController == nullptr && OverlayWidgetControllerClass)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		return OverlayWidgetController;
	}
	// If already created just return
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	// Check if classes are set
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass uninitialized. Please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass uninitialized. Please fill out BP_AuraHUD"));

	// Create UserWidget so we can cast it to OverlayWidget
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	// Set WidgetControllerParams with function parameters
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	// Get the OverlayWidgetController so we can tie the widget and the controller together
	UOverlayWidgetController* WidgetController = GetOverLayWidgetController(WidgetControllerParams);
	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}


