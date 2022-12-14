#pragma once
enum TileState
{
    TILE_NONE,
    TILE_WALL,
    TILE_DOOR,
    TILE_TRAP,
    TILE_WATER,
    TILE_SIZE
};

class ObTileMap : public GameObject
{
protected:
    VertexTile*         vertices;
    ID3D11Buffer*       vertexBuffer;
    

public:
    ObImage*            tileImages[4];
    string              file;
    Int2                tileSize;   //10x10 , 4x4
public:
    ObTileMap();
    virtual ~ObTileMap();

    void                Render() override;

    virtual void        ResizeTile(Int2 TileSize);
    void                SetTile(Int2 TileIdx, Int2 FrameIdx, int ImgIdx = 0,
        int TileState = TILE_NONE, Color color = Color(0.5f, 0.5f, 0.5f, 0.5f));

};

