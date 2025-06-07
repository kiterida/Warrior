// Jai Cuyler All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarrirorEnhancedInputComponent.generated.h"


/**
 * 
 */
UCLASS()
class WARRIOR_API UWarrirorEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject ContextObject, CallbackFunc Func);
	
};

template<class UserObject, typename CallbackFunc>
inline void UWarrirorEnhancedInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("InputConfig asset is null, cannot proceed with binding"));
	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}
