
#include "ParticleSimulationActor.h"
#include "DrawDebugHelpers.h"

AParticleSimulationActor::AParticleSimulationActor()
{
    PrimaryActorTick.bCanEverTick = true;
    UniversalRepulsionFactor = 2.0f; 
}

void AParticleSimulationActor::BeginPlay()
{
    Super::BeginPlay();

    //initialze colors
    FLinearColor purple(0.4f, 0.0f, 0.4f, 1.0f);
    FLinearColor dark_green(0.0f, 0.2f, 0.0f, 0.5f);
    FLinearColor dark_red(0.2f, 0.0f, 0.0f, 0.5f);
    FLinearColor dark_blue(0.0f, 0.0f, 0.2f, 0.5f);

    // initialize interaction strengths
    InteractionStrengths.Add(purple, TMap<FLinearColor, float>{
        {purple, -0.25f},
        { dark_red, -2.25f },
        { dark_blue, 2.25f },
        { dark_green, -0.25f }
    });
    InteractionStrengths.Add(dark_red, TMap<FLinearColor, float>{
        {purple, -0.25f},
        { dark_red, 2.25f },
        { dark_blue, -2.25f },
        { dark_green, -1.25f }
    });
    InteractionStrengths.Add(dark_green, TMap<FLinearColor, float>{
        {purple, -1.25f},
        { dark_red, -3.25f },
        { dark_blue, -2.25f },
        { dark_green, 1.25f }
    });
    InteractionStrengths.Add(dark_blue, TMap<FLinearColor, float>{
        {purple, 0.25f},
        { dark_red, -2.25f },
        { dark_blue, 2.25f },
        { dark_green, -0.25f }
    });
   
    //initialize particles
    CreateParticles(600, purple);
    CreateParticles(800, dark_red);
    CreateParticles(800, dark_green);
    CreateParticles(800, dark_blue);
    
}

/// Ticks the particle simulation, applying the simulation rules and drawing the particles.
///
/// This function is called every frame by the engine. It applies the particle interaction rules defined in the `ApplyRules` function, and then draws the current positions of all particles using the `DrawDebugPoint` function.
///
/// @param DeltaTime The time since the last frame, in seconds.
void AParticleSimulationActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ApplyRules(DeltaTime);

    //draw particles
    for (AParticle* Particle : Particles)
    {
        if (Particle)
        {
            DrawDebugPoint(GetWorld(), Particle->Position, 5.0f, Particle->Color.ToFColor(true), false, -1.0f, 0);
        }
    }
}

/// Creates a number of particles with the specified color.
///
/// This function spawns a number of particles in the world and adds them to the Particles array. The particles are positioned randomly within a bounded area, and are assigned the specified color.
///
/// @param Number The number of particles to create.
/// @param Color The color to assign to the new particles.
void AParticleSimulationActor::CreateParticles(int32 Number, FLinearColor Color)
{
    for (int32 i = 0; i < Number; ++i)
    {
        AParticle* NewParticle = GetWorld()->SpawnActor<AParticle>(AParticle::StaticClass());
        NewParticle->Position = FVector(FMath::RandRange(50.0f, 700.0f), FMath::RandRange(50.0f, 700.0f), 0);
        NewParticle->Color = Color;
        Particles.Add(NewParticle);
    }
}

void AParticleSimulationActor::ApplyRules(float DeltaTime)
{
    for (int32 i = 0; i < Particles.Num(); ++i)
    {
        AParticle* A = Particles[i];
        FVector Force = FVector::ZeroVector;

        for (int32 j = 0; j < Particles.Num(); ++j)
        {
            if (i == j) continue;

            AParticle* B = Particles[j];
            FVector Direction = A->Position - B->Position;
            float Distance = Direction.Size();
            Direction.Normalize();

            if (Distance > 0 && Distance < 50.0f)
            {
                //interaction strength between colors
                float Strength = 2.0f;

                
                if (InteractionStrengths.Contains(A->Color) && InteractionStrengths[A->Color].Contains(B->Color))
                {
                    Strength = InteractionStrengths[A->Color][B->Color];
                }

                Force += Strength * Direction;

                // apply universal repulsion factor
                if (Distance < 19.0f) 
                {
                    Force += UniversalRepulsionFactor * Direction;
                }
            }
        }

        A->Velocity = (A->Velocity + Force) * 0.8f;
        A->Position += A->Velocity * DeltaTime;
    }
}
