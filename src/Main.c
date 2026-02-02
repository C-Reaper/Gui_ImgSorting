#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"


Sprite input;
Sprite sorted;
Vec2 pos;

int Sprite_Sort(const Pixel* sp0,const Pixel* sp1){
	// const int index0 = ((void*)sp0 - (void*)sorted.img) / sizeof(Pixel);
	// const int index1 = ((void*)sp1 - (void*)sorted.img) / sizeof(Pixel);

	// const float i0 = (float)index0 / (float)sorted.w;
	// const float i1 = (float)index1 / (float)sorted.w;

	// const float x0 = i0 - (int)i0;
	// const float y0 = (float)((int)i0) / (float)sorted.h;
	// const float x1 = i1 - (int)i1;
	// const float y1 = (float)((int)i1) / (float)sorted.h;

	// const float l0 = (x0 - pos.x) * (x0 - pos.x) + (y0 - pos.y) * (y0 - pos.y);
	// const float l1 = (x1 - pos.x) * (x1 - pos.x) + (y1 - pos.y) * (y1 - pos.y);

	const float l0 = Pixel_Lightness_RGB(*sp0);
	const float l1 = Pixel_Lightness_RGB(*sp1);

	// const Pixel mp = Sprite_Get(&input,pos.x,pos.y);
	// const float l0 = Pixel_DistF(*sp0,mp);
	// const float l1 = Pixel_DistF(*sp1,mp);

	return l0 > l1;
}

void Setup(AlxWindow* w){
	input = Sprite_Load("./assets/Background.png");
	sorted = Sprite_Cpy(&input);
	pos = (Vec2){ 0.0f,0.0f };
}
void Update(AlxWindow* w){
    if(Stroke(ALX_MOUSE_L).DOWN){
		pos = GetMouse();
		//pos = Vec2_Div(GetMouse(),(Vec2){ GetWidth(),GetHeight() });

		Sprite_Free(&sorted);
		sorted = Sprite_Cpy(&input);
		qsort(sorted.img,sorted.w * sorted.h,sizeof(Pixel),(int(*)(const void*,const void*))Sprite_Sort);
	}
	
	Clear(BLACK);

	Sprite_Render(WINDOW_STD_ARGS,&input,0.0f,0.0f);
	Sprite_Render(WINDOW_STD_ARGS,&sorted,input.w,0.0f);
}
void Delete(AlxWindow* w){
    Sprite_Free(&input);
    Sprite_Free(&sorted);
}

int main(){
    if(Create("Img Sorting",2500,1250,1,1,Setup,Update,Delete))
        Start();
    return 0;
}