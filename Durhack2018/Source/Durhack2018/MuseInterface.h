// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Core/Public/Misc/InteractiveProcess.h"
#include "Engine.h"
#include "MuseInterface.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class DURHACK2018_API UMuseInterface : public UObject
{
	GENERATED_BODY()
public:
	UMuseInterface();
	~UMuseInterface();
	UFUNCTION(BlueprintCallable)
	void setup(int32 port);
	UFUNCTION(BlueprintCallable)
	float getRollingAverage();

	TArray<float> lastNAverages;
	FString URL;
	int32 pid;
	float lastAnswer = 0;
	const int N = 150;

	FInteractiveProcess *process;

	//UFUNCTION()
	//PostMessageDelegate PostMessage(const FString Message);

};
