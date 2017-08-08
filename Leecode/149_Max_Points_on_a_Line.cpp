/*
* - William SUN,
* 1.the precision of the slope, x, y should be long double, cause there are some big number
*
*
*
*
*/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() == 1)
            return 1;
        
        int max_n=0;
        
        for(int i=0;i<points.size();i++){
            Point p1 = points[i];
            long double x,y; 
            int same_n = 1;
            std::unordered_map<long double, int> hash;
            long double m=0;            
            
            for(int j=i+1;j<points.size();j++){
                //int same_n=1;
                Point p2 = points[j];
                x = p1.x - p2.x;
                y = p1.y - p2.y;
                
                if(x==0 && y==0){    //same point = 3, in case all datas are the same point
                    hash.insert({3.0, same_n});
                    ++same_n;    //same point number + other points(for the following data)

                    for(unordered_map<long double, int>::iterator iter=hash.begin();iter!=hash.end();++iter)    
                        ++(*iter).second;     //for the previous datas
                }
                else if(x==0){    //slope is vertical
                    hash.insert({2.0, same_n});    //vertical = 2
                    ++hash[2.0];
                }
                else{    //common condition
                    m = y/x;
                    hash.insert({m, same_n}); 
                    ++hash[m];               
                }
                    
                for(auto& e:hash)
                    max_n = max_n<e.second?e.second:max_n;
            }
        }
        
        return max_n;
    }
};
