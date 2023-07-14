// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/unreal_project_1LaserPinter.h"

// Sets default values
Aunreal_project_1LaserPinter::Aunreal_project_1LaserPinter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float Aunreal_project_1LaserPinter::GetEndPointOfLaserCPP(FVector Start, FVector End) const
{
	float distance = 0;
	FHitResult Result;
	if (GetWorld()->LineTraceSingleByChannel(Result, Start, End, ECollisionChannel::ECC_Visibility))
	{
		distance = Result.Distance;
	}
	else
	{
		distance = (End - Start).Length();
	}
	return distance;
}

// Called when the game starts or when spawned
void Aunreal_project_1LaserPinter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aunreal_project_1LaserPinter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

