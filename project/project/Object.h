#pragma once
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif
#include "allegro5\allegro5.h"
#include "MyBitmap.h"
#include "Config.h"
#include "Hitbox.h"
class Object : public Hitbox
{
private:
	
public:
	Object(const char *filename);
	Object(const char *filename, int posX, int posY, int x);
	Object(const char *filename, int posX, int posY, int x, int y);
	Object(const char *filename, int posX, int posY, int x, int y, double sizeX);
	Object(const char *filename, int posX, int posY, Hitbox * hitbox);
	Object(const char *filename, int posX, int posY, int x, int y, Hitbox * hitbox);
	Object(Hitbox * hitbox);
	Object(int x, int y, Hitbox * hitbox);

	void ChangeBitmap(const char *filename);
	bool CollisionCalculate(double x, double y, double objX, double objY, int objBouncerX, int objBouncerY);

	ALLEGRO_BITMAP *GetBitmap();
	Object();
	virtual ~Object();
protected: void DrawObject(int x, int y, double rotation = 0, int scale = 1);
		   int sizeX;
		   int sizeY;
		   MyBitmap * bitmapa = NULL;
		   

			
};

