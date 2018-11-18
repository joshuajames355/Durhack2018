// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Core/Public/Misc/InteractiveProcess.h"
#include "Engine.h"
#include "LeapInterface.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class DURHACK2018_API ULeapInterface : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void setup();

	FInteractiveProcess *process;
	FString lastInput;

	UFUNCTION(BlueprintCallable)
		FString getLastInput();
	
};
