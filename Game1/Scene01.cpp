#include "stdafx.h"

void Scene01::Init()
{
	pl = new Player();
	mon = new Monster();
	map = new ObTileMap();
	map->SetWorldPos(Vector2(-app.GetHalfWidth(), -app.GetHalfHeight()));
	
	//0 = 사막맵, 1 = tile2.png 파일

	//가운데 도로 만들기
	for (int i = 0; i < map->tileSize.x; i++)
	{
		for(int j = 0; j < map->tileSize.y; j++)
		{
			map->SetTile(Int2(i, j), Int2(5, 3), 0);//모래로 한번 채우고

			map->SetTile(Int2(9, j), Int2(1, 4), 0); //도로 십자로 만들기
			map->SetTile(Int2(10, j), Int2(1, 4), 0); //세로
			map->SetTile(Int2(8, j), Int2(0, 4), 0); //도로 양옆테두리
			map->SetTile(Int2(11, j), Int2(2, 4), 0); 

			map->SetTile(Int2(j, 9), Int2(1, 4), 0); //도로 십자로 만들기
			map->SetTile(Int2(j, 10), Int2(1, 4), 0); //가로
			map->SetTile(Int2(j, 8), Int2(1, 5), 0); //도로 양옆테두리
			map->SetTile(Int2(j, 11), Int2(1, 3), 0);

		}
	}

	//8,9,10,11
	for (int i = 8; i < 12; i++)
	{
		for (int j = 8; j < 12; j++)
		{
			map->SetTile(Int2(i, j), Int2(1, 4), 0);
		}
	}

	//마지막 네 귀퉁이,
	map->SetTile(Int2(8, 11), Int2(4, 5), 0); //좌 상
	map->SetTile(Int2(8, 8), Int2(4, 4), 0); //좌 하
	map->SetTile(Int2(11, 11), Int2(3, 5), 0); //우 상
	map->SetTile(Int2(11, 8), Int2(3, 4), 0); //우 하

	///도로 끝

	//사물 배치
	map->SetTile(Int2(7, 7), Int2(5, 5), 0); //표지판

	
	
	

	//길뚫기
	map->SetTile(Int2(3, 11), Int2(6, 1), 0);
	map->SetTile(Int2(4, 11), Int2(6, 1), 0);
	map->SetTile(Int2(3, 12), Int2(6, 1), 0);
	map->SetTile(Int2(4, 12), Int2(6, 1), 0);

	map->SetTile(Int2(3, 13), Int2(6, 0), 0);
	map->SetTile(Int2(4, 13), Int2(6, 0), 0);

	//집만들기 2~5, 18~15(위에서 아래)
	for (int i = 2; i < 6; i++)//가로
	{
		for (int j = 15; j < 19; j++)//세로
		{
			map->SetTile(Int2(i, j), Int2(1, 1), 0); //집 토대

			map->SetTile(Int2(2, j), Int2(0, 1), 0); //왼쪽벽
			map->SetTile(Int2(5, j), Int2(2, 1), 0); //오른쪽쪽벽

			map->SetTile(Int2(i, 18), Int2(1, 0), 0); //윗쪽벽
			map->SetTile(Int2(i, 15), Int2(1, 2), 0); //아래벽
		}
	}
	
	//집 테두리
	map->SetTile(Int2(2,18), Int2(0,0), 0); //좌 상
	map->SetTile(Int2(2,15), Int2(0,2), 0);//좌 하
	map->SetTile(Int2(5,18), Int2(2,0), 0);//우 상
	map->SetTile(Int2(5,15), Int2(2,2), 0);//우 하

	//집 주변 꾸미기


}

void Scene01::Release()
{
}

void Scene01::Update()
{
	ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());
	ImGui::SliderFloat2("Scale", (float*)&map->scale, 0.0f, 100.0f);

	pl->Update();
	mon->SetTarget(pl->GetPos());
	mon->Update();
	map->Update();

	CAM->position = pl->GetPos();
}

void Scene01::LateUpdate()
{
	
}

void Scene01::Render()
{
	map->Render();
	pl->Render();
	mon->Render();

	//								L    T    R    B
	//DWRITE->RenderText(L"hi", RECT{100, 100, 100, 100}, 300.0f);
	DWRITE->RenderText(L"안녕\n안녕", RECT{ 100, 100, (long)app.GetWidth(), (long)app.GetHeight() }, 100.0f,
		L"궁서", Color(1.0f, 0.0f, 0.0f, 1.0f), DWRITE_FONT_WEIGHT_BOLD,
		DWRITE_FONT_STYLE_ITALIC);
}

void Scene01::ResizeScreen()
{

}
