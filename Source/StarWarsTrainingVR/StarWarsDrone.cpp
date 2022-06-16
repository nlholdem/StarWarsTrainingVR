// Fill out your copyright notice in the Description page of Project Settings.


#include "StarWarsDrone.h"

// Sets default values
AStarWarsDrone::AStarWarsDrone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Xcontroller = new PIDController(-100.0, 100.0, 0.01, 0.001, 0.05);
	Ycontroller = new PIDController(-100.0, 100.0, 0.01, 0.001, 0.05);
	Zcontroller = new PIDController(-100.0, 100.0, 0.01, 0.001, 0.05);
	UE_LOG(LogTemp, Warning, TEXT("Constructing drone... "));

}

// Called when the game starts or when spawned
void AStarWarsDrone::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Starting drone... "));

}

// Called every frame
void AStarWarsDrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Drone..."));
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	//	UE_LOG(LogTemp, Warning, TEXT("DRONE......  %f"), NewLocation.Z);

	NewLocation.X += Xcontroller->update(-200.0, NewLocation.X, DeltaTime);
	NewLocation.Y += Ycontroller->update(0.0, NewLocation.Y, DeltaTime);
	NewLocation.Z += Zcontroller->update(90.0, NewLocation.Z, DeltaTime);
	SetActorLocationAndRotation(NewLocation, NewRotation);

	FVector loc = Enemy->GetActorLocation();
	FRotator rot = Enemy->GetActorRotation();
	UE_LOG(LogTemp, Warning, TEXT("Roll: %f Pitch %f Yaw: %f"), rot.Roll, rot.Pitch, rot.Yaw);
	UE_LOG(LogTemp, Warning, TEXT("X: %f Y%f Z: %f"), loc.X, loc.Y, loc.Z);


}

