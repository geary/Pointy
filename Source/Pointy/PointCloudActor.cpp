#include "Pointy.h"
#include "PointCloudActor.h"


// Sets default values
APointCloudActor::APointCloudActor() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//USphereComponent* sphereComponent = CreateDefaultSubobject<USphereComponent>( TEXT("RootComponent") );
	//RootComponent = sphereComponent;
	//sphereComponent->InitSphereRadius( 40.0f );
	//sphereComponent->SetCollisionProfileName( "Pawn" );

	//UStaticMeshComponent* sphereMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("VisualRepresentation") );
	//sphereMesh->AttachTo( RootComponent );
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> sphereMeshAsset( TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere") );
	//if( sphereMeshAsset.Succeeded() ) {
	//	sphereMesh->SetStaticMesh( sphereMeshAsset.Object );
	//	sphereMesh->SetRelativeLocation( FVector::ZeroVector );
	//	sphereMesh->SetWorldScale3D( FVector(0.8f) );
	//}

	pointicles = CreateDefaultSubobject<UParticleSystemComponent>( TEXT("Pointicles") );

	//pointicles->AttachTo( sphereMesh );
	pointicles->AttachTo( RootComponent );
	//pointicles->bAutoActivate = true;
	//pointicles->SetRelativeLocation( FVector(0.0f, 0.0f, 0.0f) );

	//static ConstructorHelpers::FObjectFinder<UParticleSystem> particleAsset( TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire") );
	pointiclesSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>( TEXT("/Game/P_Fire.P_Fire") );
	//static ConstructorHelpers::FObjectFinder<UParticleSystem> particleAsset( TEXT("/Game/StarterContent/Particles/P_Sparks.P_Sparks") );
	//static ConstructorHelpers::FObjectFinder<UParticleSystem> particleAsset( TEXT("/Game/Pointy.Pointy") );
	if( particleAsset.Succeeded() ) {
		pointicles->SetTemplate( particleAsset.Object );
	}

	//sphereComponent->SetSimulatePhysics(true);

	//pointicles = CreateDefaultSubobject<UParticleSystemComponent>( TEXT("Pointicles") );
	//pointicles->AttachTo( RootComponent );

	//RootComponent = pointicles;
	//auto b = pointicles->bAutoActivate;
	//pointicles->bAutoActivate = true;
	//pointicles->SetRelativeLocation( FVector::ZeroVector );
}

// Called when the game starts or when spawned
void APointCloudActor::BeginPlay() {
	Super::BeginPlay();
	
	//pointicles->Activate( true );

	UGameplayStatics::SpawnEmitterAtLocation( GetWorld(), particleAsset, GetActorLocation(), FRotator::ZeroRotator, false );
}

// Called every frame
void APointCloudActor::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );

}

