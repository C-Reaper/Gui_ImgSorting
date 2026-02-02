#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"


Sprite input;
Sprite sorted;
Vec2 pos;

int Sprite_Sort(const Pixel* sp0,const Pixel* sp1){
	const float l0 = Pixel_Lightness_RGB(*sp0);
	const float l1 = Pixel_Lightness_RGB(*sp1);
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

		Sprite_Free(&sorted);
		sorted = Sprite_Cpy(&input);
		qsort(sorted.img,sorted.w * sorted.h,sizeof(Pixel),Sprite_Sort);
	}
	
	Clear(BLACK);

	Sprite_Render(WINDOW_STD_ARGS,&input,0.0f,0.0f);
	Sprite_Render(WINDOW_STD_ARGS,&sorted,input.w,0.0f);
}
void Delete(AlxWindow* w){
    
}

int main(){
    if(Create("Img Sorting",1920,1080,1,1,Setup,Update,Delete))
        Start();
    return 0;
}