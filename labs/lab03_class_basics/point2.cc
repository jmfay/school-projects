#include<cmath>

using namespace std;

Point2::Point2(float _x, float _y){
  x = _x;
  y = _y;
}

float Point2::DistanceBetween(Point2 nextp){
  return sqrt(pow((nextp.x - this.x),2) + pow((nextp.y - this.y),2));
}

int Point2::Quadrant(){
  if (this.x >= 1 && this.y >= 0){
    return 1;
  }
  else if (this.x <= 0 && this.y >= 1){
    return 2;
  }
  else if (this.x <= -1 && this.y <= 0){
    return 3;
  }
  else if (this.x >=0 && this.y <= -1){
    return 4;
  }
  else if (this.x == 0 && this.y == 0){
    return 0;
  }
}

Point2::Print(){
  std
}
