// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "unreal_project_1LaserPinter.generated.h"

UCLASS()
class Aunreal_project_1LaserPinter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aunreal_project_1LaserPinter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
