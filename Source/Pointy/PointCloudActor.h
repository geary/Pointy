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

	APointCloudActor();

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaSeconds ) override;

private:

	void SpawnXYZ( float x, float y, float z );
	void SpawnPoint( FVector point );
	
};
