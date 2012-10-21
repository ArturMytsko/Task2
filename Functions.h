/**
 * @file   Functions.h
 * @brief  Contains declaration functions which solve the task
 * @author Arthur Mytsko
 */

typedef unsigned long UL;
typedef unsigned char UCH;
typedef unsigned int  UI;

//struct to save information about each triangle
struct Triangle
{
	struct Coordinates
	{
		int x;
		int y;
	} Point[3];
	float fPerimeter;
} ;

 /**
   * @brief      Implement valid inputing coordinates for triangles
   * @param	[in] pTriangle - pointer to triangles array
   * @param	[in] uiCount - count of triangles
   * @return	 void
   */
void FillData(Triangle *pTriangle, UI uiCount);

 /**
   * @brief      Implement valid inputing triangle count
   * @return	 unsigned int number - count of triangles
   */
UI InputTriangleCount();

 /**
   * @brief      Check valid coordinates and calculate perimeter 
   * @param	[in] pTriangle - pointer to triangles array
   * @return	 true, if triangle is exist
   */
bool SetPerimeter(Triangle *pTriangle);

 /**
   * @brief      Sorting triangles in increasing to perimeter
   * @param	[in] pTriangle - pointer to triangles array
   * @param	[in] uiCount - count of triangles
   * @return	 void
   */
void SortData(Triangle *pTriangle, UI uiCount);

 /**
   * @brief      Printing info about triangles
   * @param	[in] pTriangle - pointer to triangles array
   * @param	[in] uiCount - count of triangles
   * @return	 void
   */
void PrintTable(Triangle *pTriangle, UI uiCount);

 /**
   * @brief      Calculate percent of triangles wich perimeters 
   *             are above 2x minimal perimeter
   * @param	[in] pTriangle - pointer to triangles array
   * @param	[in] uiCount - count of triangles
   * @return	 float number - percent of triangles
   */
float GetMinP2xCount(Triangle *pTriangle, UI uiCount);