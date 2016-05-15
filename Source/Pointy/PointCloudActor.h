#pragma once

#include "GameFramework/Actor.h"
#include "PointCloudActor.generated.h"

UCLASS()
class POINTY_API APointCloudActor : public AActor
{
	GENERATED_BODY()

public:

	//UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = UnitProperties )
	UParticleSystem* pointicleSystem;
	UParticleSystemComponent* pointicles;

	// Sets default values for this actor's properties
	APointCloudActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:

	void SpawnPoint( FVector point );
	
};
