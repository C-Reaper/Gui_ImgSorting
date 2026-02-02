#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"


Sprite input;
Sprite sorted;

int Sprite_Sort(const Pixel* sp0,const Pixel* sp1){
	return Pixel_Lightness_RGB(*sp0) > Pixel_Lightness_RGB(*sp1);
}

void Setup(AlxWindow* w){
	
}
void Update(AlxWindow* w){
    if(Stroke(ALX_KEY_W).DOWN){
		speed *= 1.01f;
	}
	if(Stroke(ALX_KEY_S).DOWN){
		speed *= 0.99f;
	}
	
	Clear(BLACK);

	for(int i = 0;i<stars.size;i++){
		Vec3* p = (Vec3*)Vector_Get(&stars,i);
		const Vec2 pp = World_Screen(*p);

		p->z -= speed * w->ElapsedTime;
		if(p->z < 0.01f){
			Vector_Remove(&stars,i);
			i--;
			continue;
		}

		const Vec2 ap = World_Screen(*p);
		Line_RenderX(WINDOW_STD_ARGS,pp,ap,WHITE,1.0f);
		//Circle_RenderX(WINDOW_STD_ARGS,World_Screen(*p),1.0f,WHITE);
	}


	for(int i = stars.size;i<STARS_MAX;i++){
		Vector_Push(&stars,(Vec3[]){{
			.x = Random_f64_MinMax(-10.0f,10.0f),
			.y = Random_f64_MinMax(-10.0f,10.0f),
			.z = Random_f64_MinMax(5.0f,15.0f)
		}});
	}
}
void Delete(AlxWindow* w){
    Vector_Free(&stars);
}

int main(){
    if(Create("Star Field",1920,1080,1,1,Setup,Update,Delete))
        Start();
    return 0;
}