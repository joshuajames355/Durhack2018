// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MuseInterface.h"
#include "InputDeviceHelpers.generated.h"

/**
 * 
 */
UCLASS()
class DURHACK2018_API UInputDeviceHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UInputDeviceHelpers();
	~UInputDeviceHelpers();

	//UFUNCTION(BlueprintCallable, Category = "CustomInput")
	//static void setup();

	//static UMuseInterface* mInterface;
	
};

