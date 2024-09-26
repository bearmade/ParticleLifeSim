  #include "Particle.h"

  AParticle::AParticle()
  {
      PrimaryActorTick.bCanEverTick = true;
  }

  void AParticle::Tick(float DeltaTime)
  {
      Super::Tick(DeltaTime);

      //update position
      Position += Velocity * DeltaTime;

      //collision handling
      const float Boundary = 750.0f;
      const float Epsilon = 1.0f;

      if (Position.X <= Epsilon || Position.X >= Boundary - Epsilon)
      {
          Velocity.X *= -1;
          Position.X = FMath::Clamp(Position.X, Epsilon, Boundary - Epsilon);
      }

      if (Position.Y <= Epsilon || Position.Y >= Boundary - Epsilon)
      {
          Velocity.Y *= -1;
          Position.Y = FMath::Clamp(Position.Y, Epsilon, Boundary - Epsilon);
      }

      // clamp position
      Position.X = FMath::Clamp(Position.X, 0.0f, Boundary);
      Position.Y = FMath::Clamp(Position.Y, 0.0f, Boundary);

      SetActorLocation(Position);
  }
