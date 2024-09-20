
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particle.generated.h"

UCLASS()
class PARTICLELIFESIM_API AParticle : public AActor
{
    GENERATED_BODY()

public:
    AParticle();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
    FVector Position;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
    FVector Velocity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
    FLinearColor Color; 

    virtual void Tick(float DeltaTime) override;
};
