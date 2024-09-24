#pragma once
#include "ParticleLifeHUD.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particle.h"
#include "ParticleSimulationActor.generated.h"

UCLASS()
class PARTICLELIFESIM_API AParticleSimulationActor : public AActor
{
    GENERATED_BODY()

public:
    AParticleSimulationActor();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY()
    AParticleLifeHUD* ParticleLifeHUD;

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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    float RedPurpleStrength;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    float RedRedStrength;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    float RedGreenStrength;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    float RedBlueStrength;



private:
    void CreateParticles(int32 Number, FLinearColor Color);
    void ApplyRules(float DeltaTime);
    TArray<AParticle*> Particles;

    TMap<FLinearColor, TMap<FLinearColor, float>> InteractionStrengths;

    float UniversalRepulsionFactor;
    FLinearColor* purple;
    FLinearColor* green;
    FLinearColor* red;
    FLinearColor* blue;




};







