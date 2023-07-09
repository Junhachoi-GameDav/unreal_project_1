// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/unreal_project_1Character.h"

// Sets default values
Aunreal_project_1Character::Aunreal_project_1Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aunreal_project_1Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aunreal_project_1Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Aunreal_project_1Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

