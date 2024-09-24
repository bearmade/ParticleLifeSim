// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ParticleLifeHUD.generated.h"

/**
 * 
 */
UCLASS()
class PARTICLELIFESIM_API AParticleLifeHUD : public AHUD
{
	GENERATED_BODY()

public:

	AParticleLifeHUD();
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float PurplePurpleStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float PurpleRedStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float PurpleGreenStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float PurpleBlueStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float GreenPurpleStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float GreenRedStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float GreenGreenStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float GreenBlueStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float BluePurpleStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float BlueRedStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float BlueGreenStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float BlueBlueStrength;
	UPROPERTY(EditAnywhere,	BlueprintReadWrite, Category = "Interaction")
	float RedPurpleStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float RedRedStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float RedGreenStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float RedBlueStrength;
	

	// Add similar UPROPERTY declarations for other interaction strengths

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void UpdateInteractionStrength(FString ColorA, FString ColorB, float NewStrength);
};

