#pragma once

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

private:
    void CreateParticles(int32 Number, FLinearColor Color);
    void ApplyRules(float DeltaTime);
    TArray<AParticle*> Particles;

    TMap<FLinearColor, TMap<FLinearColor, float>> InteractionStrengths;

    float UniversalRepulsionFactor;
};



