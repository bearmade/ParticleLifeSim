
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

   //initialize colors
    purple = new FLinearColor(0.4f, 0.0f, 0.4f, 1.0f);
    green = new FLinearColor(0.0f, 0.2f, 0.0f, 0.5f);
    red = new FLinearColor(0.2f, 0.0f, 0.0f, 0.5f);
    blue = new FLinearColor(0.0f, 0.0f, 0.2f, 0.5f);
    // initialize interaction strengths
    InteractionStrengths.Add(*purple, TMap<FLinearColor, float>{
        {*purple, -0.25f},
        { *red, -2.25f },
        { *blue, 2.25f },
        { *green, -0.25f }
    });
    InteractionStrengths.Add(*red, TMap<FLinearColor, float>{
        {*purple, -0.25f},
        { *red, 2.25f },
        { *blue, -2.25f },
        { *green, -1.25f }
    });
    InteractionStrengths.Add(*green, TMap<FLinearColor, float>{
        {*purple, -1.25f},
        { *red, -3.25f },
        { *blue, -2.25f },
        { *green, 1.25f }
    });
    InteractionStrengths.Add(*blue, TMap<FLinearColor, float>{
        {*purple, 0.25f},
        { *red, -2.25f },
        { *blue, 2.25f },
        { *green, -0.25f }
    });

   
    //initialize particles
    CreateParticles(800, *purple);
    CreateParticles(800, *red);
    CreateParticles(800, *green);
    CreateParticles(800, *blue);
    
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        ParticleLifeHUD = Cast<AParticleLifeHUD>(PlayerController->GetHUD());
    }
}

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
                  float Strength;
                  if (ParticleLifeHUD)
                  {
                      if (A->Color == *purple && B->Color == *purple)
                          Strength = ParticleLifeHUD->PurplePurpleStrength;
                      else if (A->Color == *purple && B->Color == *red)
                          Strength = ParticleLifeHUD->PurpleRedStrength;
                      else if (A->Color == *purple && B->Color == *green)
                          Strength = ParticleLifeHUD->PurpleGreenStrength;
                      else if (A->Color == *purple && B->Color == *blue)
                          Strength = ParticleLifeHUD->PurpleBlueStrength;
                      else if (A->Color == *red && B->Color == *purple)
                          Strength = ParticleLifeHUD->RedPurpleStrength;
                      else if (A->Color == *red && B->Color == *red)
                          Strength = ParticleLifeHUD->RedRedStrength;
                      else if (A->Color == *red && B->Color == *green)
                          Strength = ParticleLifeHUD->RedGreenStrength;
                      else if (A->Color == *red && B->Color == *blue)
                          Strength = ParticleLifeHUD->RedBlueStrength;
                      else if (A->Color == *green && B->Color == *purple)
                          Strength = ParticleLifeHUD->GreenPurpleStrength;
                      else if (A->Color == *green && B->Color == *red)
                          Strength = ParticleLifeHUD->GreenRedStrength;
                      else if (A->Color == *green && B->Color == *green)
                          Strength = ParticleLifeHUD->GreenGreenStrength;
                      else if (A->Color == *green && B->Color == *blue)
                          Strength = ParticleLifeHUD->GreenBlueStrength;
                      else if (A->Color == *blue && B->Color == *purple)
                          Strength = ParticleLifeHUD->BluePurpleStrength;
                      else if (A->Color == *blue && B->Color == *red)
                          Strength = ParticleLifeHUD->BlueRedStrength;
                      else if (A->Color == *blue && B->Color == *green)
                          Strength = ParticleLifeHUD->BlueGreenStrength;
                      else if (A->Color == *blue && B->Color == *blue)
                          Strength = ParticleLifeHUD->BlueBlueStrength;
                  }

                  Force += Strength * Direction;

                  // apply universal repulsion factor
                  if (Distance < ParticleLifeHUD->UniversalRepulsionDistance) 
                  {
                      Force += ParticleLifeHUD->UniversalRepulsionFactor * Direction;
                  }
              }
          }

          A->Velocity = (A->Velocity + Force) * ParticleLifeHUD->UniversalRepulsionModifier;
          A->Position += A->Velocity * ((DeltaTime)/(10.0f)) ;
        
      }
  }