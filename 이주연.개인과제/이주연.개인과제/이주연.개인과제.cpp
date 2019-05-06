#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#include <stdio.h>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")


int main() {

	//두점 입력받기
	int sx, sy, sz, ex, ey, ez;
	printf("두 점의 좌표를 입력하세요:");
	scanf("%d %d %d %d %d %d", &sx, &sy, &sz, &ex, &ey, &ez);

	int x1 = MIN(sx, ex);
	int y1 = MIN(sy, ey);
	int z1 = MIN(sz, ez);
	int x2 = MAX(sx, ex);
	int y2 = MAX(sy, ey);
	int z2 = MAX(sz, ez);
	int x, y, z;
	int a = (x1 + x2) / 2;
	int b = (z1 + z2) / 2;

	//건물 생성에 필요한 블록 만들기
	BricksID bricks1 = createBricks(BRICKS_STONE);
	PlanksID wood = createPlanks(PLANKS_DARK_OAK);
	WoolID leaf = createWool(COLOR_LIME);
	BlockID dirt = createBlock(BLOCK_DIRT);


	//화단 만들기
	for (x = x1; x <= x2; x++) {
		for (z = z1; z <= z2; z++) {
			locateBlock(bricks1, x, y1, z);
		}
	}
	//화단에 흙 채우기
	for (x = x1 + 3; x < (x2 - 2); x++) {
		for (z = z1 + 3; z < (z2 - 2); z++) {
			locateBlock(dirt, x, y1, z);
		}
	}


	//새싹 만들기
	if (y2 - y1 <= 10) {
		//새싹 줄기&잎 만들기
		for (y = y1 + 1; y <= (y2 - 2); y++) {
			locateBlock(leaf, (x1 + x2) / 2, y, (z1 + z2) / 2);
		}
		locateBlock(leaf, a + 1, y2 - 1, b);
		locateBlock(leaf, a + 2, y2, b);
		locateBlock(leaf, a - 1, y2 - 1, b);
		locateBlock(leaf, a - 2, y2, b);
	}


	//나무 만들기
	else {
		//나무기둥 만들기
		for (x = x1 + 8; x < (x2 - 7); x++) {
			for (z = z1 + 8; z < (z2 - 7); z++) {
				for (y = y1; y <= y2; y++) {
					locateBlock(wood, x, y, z);
				}
			}
		}

		//나뭇잎 만들기
		for (x = x1 + 4; x < (x2 - 3); x++) {
			for (z = z1 + 4; z < (z2 - 3); z++) {
				locateBlock(leaf, x, y2, z);
			}
		}
		for (x = x1 + 2; x < (x2 - 1); x++) {
			for (z = z1 + 2; z < z2 - 1; z++) {
				locateBlock(leaf, x, y2 - 2, z);
				locateBlock(leaf, x, y2 - 4, z);
			}
		}
		for (x = x1 + 3; x < (x2 - 2); x++) {
			for (z = z1 + 3; z < (z2 - 2); z++) {
				locateBlock(leaf, x, y2 - 1, z);
			}
		}
		for (x = x1 + 1; x < x2; x++) {
			for (z = z1 + 1; z < z2; z++) {
				locateBlock(leaf, x, y2 - 3, z);
			}
		}
	}


}