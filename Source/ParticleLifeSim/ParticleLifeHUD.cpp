// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleLifeHUD.h"
#include "Blueprint/UserWidget.h"

AParticleLifeHUD::AParticleLifeHUD()
{
    // Constructor logic here
}

void AParticleLifeHUD::DrawHUD()
{
    Super::DrawHUD();
    // Draw a simple message on the screen
    //DrawText(FString("My Hud"), FLinearColor::White, 100.0f, 100.0f, nullptr, 1.0f, 1.0f);
    

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
    

    // Add similar conditions for other color combinations
}
