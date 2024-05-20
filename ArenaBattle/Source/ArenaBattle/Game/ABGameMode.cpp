// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
#include "ABGameMode.h"

AABGameMode::AABGameMode()
{
	//static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));		// 클래스형에 대해서는 Copy Reference로 들고온 에셋주소의 ''는 생략해 주고 경로만 입력해주고, 클래스 정보를 가져올 것이기 때문에 _C를 붙여 준다.

	//if (ThirdPersonClassRef.Class)
	//{
	//	DefaultPawnClass = ThirdPersonClassRef.Class;
	//}
	// DefaultPawnClass

	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/Engine.Blueprint'/Game/ArenaBattle/Blueprint/BP_ABCharacterPlayer.BP_ABCharacterPlayer_C'"));
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerRef(TEXT("/Script/ArenaBattle.ABPlayerController"));		// 위와 동일하게 적용. 이 경우 기본으로 클래스 정보가 복제된 것이기 때문에 _C를 붙이지 않아도 된다.

	if (PlayerControllerRef.Class)
	{
		PlayerControllerClass = PlayerControllerRef.Class;		// 이 경우 에셋으로부터 직접 참조를 받기 때문에 헤더 파일의 의존성을 줄일 수 있다.
	}
}
