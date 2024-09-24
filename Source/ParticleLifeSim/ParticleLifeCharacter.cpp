// Fill out your copyright notice in the Description page of Project Settings.
#include "ParticleLifeCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AParticleLifeCharacter::AParticleLifeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Disable gravity for the character
    GetCharacterMovement()->GravityScale = 0.0f;

}

// Called when the game starts or when spawned
void AParticleLifeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AParticleLifeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AParticleLifeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



