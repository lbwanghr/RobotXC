#pragma once
#include <vector>
using namespace std;
class XCMap{
public:
	int M,N;	//地图由M行N列单元格构成
	int x_start,y_start,x_end,y_end;								//定义起点和终点的坐标
	std::vector<std::vector<int>> m_maze;							//二维数组存储障碍信息
	std::vector<std::vector<int>> m_weight;							//二维数组存储地格权值
	std::vector<std::vector<int>> m_dynamicObstacleLife;			//二维数组存储动态障碍物的生命值
	std::vector<std::vector<int>> m_dilate_maze;					//二维数组存储障碍信息
	std::vector<std::vector<int>> m_dilate_dynamicObstacleLife;		//二维数组存储障碍信息
	XCMap(int _M,int _N):M(_M),N(_N){
		x_start=x_end=y_start=y_end=-1;
		//初始化时即设定二位向量规模提高程序运行效率
		m_maze.resize(M);
		m_weight.resize(M);
		m_dynamicObstacleLife.resize(M);
		for(int i=0;i<M;i++){
			m_maze[i].resize(N);
			m_weight[i].resize(N);
			m_dynamicObstacleLife[i].resize(N);
		}
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				m_maze[i][j]=0;
				m_weight[i][j]=0;
				m_dynamicObstacleLife[i][j]=0;
			}
		}

	}
	~XCMap(){}
};