// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleLifeHUD.h"
#include "Blueprint/UserWidget.h"

AParticleLifeHUD::AParticleLifeHUD()
{
    
}

void AParticleLifeHUD::DrawHUD()
{
    Super::DrawHUD();
 
    

}
void AParticleLifeHUD::UpdateUniversalRepulsionFactor(float NewFactor)
{
    UniversalRepulsionFactor = NewFactor;
}

void AParticleLifeHUD::UpdateUniversalRepulsionModifier(float NewFactor)
{
    UniversalRepulsionModifier = NewFactor;
}

void AParticleLifeHUD::UpdateUniversalRepulsionDistance(float NewFactor)
{
    UniversalRepulsionDistance = NewFactor;
}

void AParticleLifeHUD::timeScaler(float NewFactor)
{
    timeScale = NewFactor;
}

void AParticleLifeHUD::UpdateInteractionStrength(FString ColorA, FString ColorB, float NewStrength)
{
    // Update the appropriate strength based on ColorA and ColorB
    if (ColorA == "Purple" && ColorB == "Purple")
        PurplePurpleStrength = NewStrength;
    else if (ColorA == "Purple" && ColorB == "Red")
    PurpleRedStrength = NewStrength;
    else if (ColorA == "Purple" && ColorB == "Blue")
    PurpleBlueStrength = NewStrength;
    else if (ColorA == "Purple" && ColorB == "Green")
    PurpleGreenStrength = NewStrength;
    else if (ColorA == "Red" && ColorB == "Purple")
    RedPurpleStrength = NewStrength;
    else if (ColorA == "Red" && ColorB == "Red")
    RedRedStrength = NewStrength;
    else if (ColorA == "Red" && ColorB == "Blue")
    RedBlueStrength = NewStrength;
    else if (ColorA == "Red" && ColorB == "Green")
    RedGreenStrength = NewStrength;
    else if (ColorA == "Blue" && ColorB == "Purple")
    BluePurpleStrength = NewStrength;
    else if (ColorA == "Blue" && ColorB == "Red")
    BlueRedStrength = NewStrength;
    else if (ColorA == "Blue" && ColorB == "Blue")
    BlueBlueStrength = NewStrength;
    else if (ColorA == "Blue" && ColorB == "Green")
    BlueGreenStrength = NewStrength;
    else if (ColorA == "Green" && ColorB == "Purple")
    GreenPurpleStrength = NewStrength;
    else if (ColorA == "Green" && ColorB == "Red")
    GreenRedStrength = NewStrength;
    else if (ColorA == "Green" && ColorB == "Blue")
    GreenBlueStrength = NewStrength;
    else if (ColorA == "Green" && ColorB == "Green")
    GreenGreenStrength = NewStrength;
    

}
