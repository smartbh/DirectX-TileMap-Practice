#include "stdafx.h"

void Scene01::Init()
{
	pl = new Player();
	mon = new Monster();
	map = new ObTileMap();
	map->SetWorldPos(Vector2(-app.GetHalfWidth(), -app.GetHalfHeight()));
	
	//0 = �縷��, 1 = tile2.png ����

	//��� ���� �����
	for (int i = 0; i < map->tileSize.x; i++)
	{
		for(int j = 0; j < map->tileSize.y; j++)
		{
			map->SetTile(Int2(i, j), Int2(5, 3), 0);//�𷡷� �ѹ� ä���

			map->SetTile(Int2(9, j), Int2(1, 4), 0); //���� ���ڷ� �����
			map->SetTile(Int2(10, j), Int2(1, 4), 0); //����
			map->SetTile(Int2(8, j), Int2(0, 4), 0); //���� �翷�׵θ�
			map->SetTile(Int2(11, j), Int2(2, 4), 0); 

			map->SetTile(Int2(j, 9), Int2(1, 4), 0); //���� ���ڷ� �����
			map->SetTile(Int2(j, 10), Int2(1, 4), 0); //����
			map->SetTile(Int2(j, 8), Int2(1, 5), 0); //���� �翷�׵θ�
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

	//������ �� ������,
	map->SetTile(Int2(8, 11), Int2(4, 5), 0); //�� ��
	map->SetTile(Int2(8, 8), Int2(4, 4), 0); //�� ��
	map->SetTile(Int2(11, 11), Int2(3, 5), 0); //�� ��
	map->SetTile(Int2(11, 8), Int2(3, 4), 0); //�� ��

	///���� ��

	//�繰 ��ġ
	map->SetTile(Int2(7, 7), Int2(5, 5), 0); //ǥ����

	
	
	

	//��ձ�
	map->SetTile(Int2(3, 11), Int2(6, 1), 0);
	map->SetTile(Int2(4, 11), Int2(6, 1), 0);
	map->SetTile(Int2(3, 12), Int2(6, 1), 0);
	map->SetTile(Int2(4, 12), Int2(6, 1), 0);

	map->SetTile(Int2(3, 13), Int2(6, 0), 0);
	map->SetTile(Int2(4, 13), Int2(6, 0), 0);

	//������� 2~5, 18~15(������ �Ʒ�)
	for (int i = 2; i < 6; i++)//����
	{
		for (int j = 15; j < 19; j++)//����
		{
			map->SetTile(Int2(i, j), Int2(1, 1), 0); //�� ���

			map->SetTile(Int2(2, j), Int2(0, 1), 0); //���ʺ�
			map->SetTile(Int2(5, j), Int2(2, 1), 0); //�������ʺ�

			map->SetTile(Int2(i, 18), Int2(1, 0), 0); //���ʺ�
			map->SetTile(Int2(i, 15), Int2(1, 2), 0); //�Ʒ���
		}
	}
	
	//�� �׵θ�
	map->SetTile(Int2(2,18), Int2(0,0), 0); //�� ��
	map->SetTile(Int2(2,15), Int2(0,2), 0);//�� ��
	map->SetTile(Int2(5,18), Int2(2,0), 0);//�� ��
	map->SetTile(Int2(5,15), Int2(2,2), 0);//�� ��

	//�� �ֺ� �ٹ̱�


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
	DWRITE->RenderText(L"�ȳ�\n�ȳ�", RECT{ 100, 100, (long)app.GetWidth(), (long)app.GetHeight() }, 100.0f,
		L"�ü�", Color(1.0f, 0.0f, 0.0f, 1.0f), DWRITE_FONT_WEIGHT_BOLD,
		DWRITE_FONT_STYLE_ITALIC);
}

void Scene01::ResizeScreen()
{

}
