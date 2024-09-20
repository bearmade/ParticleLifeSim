
#include "Particle.h"

AParticle::AParticle()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AParticle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

   
    Position += Velocity * DeltaTime;

    // bounding box
    if (Position.X <= 0 || Position.X >= 750) Velocity.X *= -1;
    if (Position.Y <= 0 || Position.Y >= 750) Velocity.Y *= -1;

    SetActorLocation(Position);
}
