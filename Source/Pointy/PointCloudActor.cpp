#include "Pointy.h"
#include "PointCloudActor.h"


APointCloudActor::APointCloudActor() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	pointicles = CreateDefaultSubobject<UParticleSystemComponent>( TEXT("Pointicles") );

	pointicles->AttachTo( RootComponent );
	pointicles->bAutoActivate = false;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> particleAsset( TEXT("/Game/P_Fire.P_Fire") );
	if( particleAsset.Succeeded() ) {
		pointicleSystem = particleAsset.Object;
		pointicles->SetTemplate( pointicleSystem );
	}
}

void APointCloudActor::BeginPlay() {
	Super::BeginPlay();
	
	auto point = GetActorLocation();
	auto count = 10, distance = 25;

	for( auto iX = 0;  iX < count;  iX++ ) {
		for( auto iY = 0;  iY < count;  iY++ ) {
			for( auto iZ = 0;  iZ < count;  iZ++ ) {
				SpawnXYZ(
					point.X + iX * distance,
					point.Y + iY * distance,
					point.Z + iZ * distance
				);
			}
		}
	}
}

void APointCloudActor::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
}

void APointCloudActor::SpawnXYZ( float x, float y, float z ) {
	SpawnPoint( FVector( x, y, z ) );
}

void APointCloudActor::SpawnPoint( FVector point ) {
	UGameplayStatics::SpawnEmitterAtLocation( GetWorld(), pointicleSystem, point, FRotator::ZeroRotator, false );
}
