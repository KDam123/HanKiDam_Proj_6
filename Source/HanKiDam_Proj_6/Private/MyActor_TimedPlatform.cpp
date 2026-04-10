#include "MyActor_TimedPlatform.h"

// Sets default values
AMyActor_TimedPlatform::AMyActor_TimedPlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Scrapopolis/Meshes/Props/SM_Debris_rock_4.SM_Debris_rock_4"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}


	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 90.0f;

}

// Called when the game starts or when spawned
void AMyActor_TimedPlatform::BeginPlay()
{
	Super::BeginPlay();

	MaxRange = 500.0f;

	//에디터에 배치된 현재 위치를 가져와서 두 변수에 똑같이 저장
	FVector CurrentPos = GetActorLocation();
	//시작위치를 저장
	StartLocation = CurrentPos;
	MoveLocation = CurrentPos;
	//처음 이동 방향 설정
	Direction = FVector(-1, 0, 0);

	//배치할때마다 속도가 제각각
	MoveSpeed = FMath::RandRange(200.0f, 800.0f);

	// 5초 뒤에 DestroyPlatform 함수 실행
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AMyActor_TimedPlatform::DestroyPlatform, 5.0f, false);

}

// Called every frame
void AMyActor_TimedPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//  이동시키기 (위치 = 현재위치 + 방향 * 속도 * 시간)
	MoveLocation += (Direction * MoveSpeed * DeltaTime);
	SetActorLocation(MoveLocation);

	//  왕복 로직: 시작점에서 얼마나 멀어졌나?
	float DistanceMoved = FVector::Dist(StartLocation, MoveLocation);

	if (DistanceMoved >= MaxRange)
	{
		Direction = -Direction;

		// 오차 누적 방지를 위해 시작 위치를 현재 위치로 갱신
		StartLocation = MoveLocation;
	}


}

void AMyActor_TimedPlatform::DestroyPlatform()
{
	Destroy(); // 액터를 월드에서 삭제
}

