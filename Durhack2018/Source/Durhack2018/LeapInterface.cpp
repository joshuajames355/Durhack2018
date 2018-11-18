// Fill out your copyright notice in the Description page of Project Settings.

#include "LeapInterface.h"

void ULeapInterface::setup()
{
	process = new FInteractiveProcess(FString("python C:/Users/ibmiz/Documents/GitHub/Durhack2018/Durhack2018/leapController.py"), FString(""), true);
	process->Launch();
	process->OnOutput().BindLambda([=](const FString& message)
	{
		lastInput = message;
		GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Red, message);
	});
}

FString ULeapInterface::getLastInput()
{
	FString temp = FString (lastInput);
	lastInput = "";
	return temp;
}
