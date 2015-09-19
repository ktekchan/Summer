/*
 * Khushboo Tekchandani
 * Yelp like system
 * Sample one interview question
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Calculates distance given a pair of coordinates
double calcDist(double lat1, double lon1, double lat2, double lon2){
   double dist = sqrt(((lat1-lat2)*(lat1-lat2)) + ((lon1-lon2)*(lon1-lon2)));
   return dist;
}

// Represents a restaurant
class Restaurant{
   protected:
      long id;
      string name;
      double latitude;
      double longitude;
      long openTime;
      long closeTime;
      long rating;
    public:
      Restaurant();
      //getters and setters
      double getLon() {return longitude;}
      double getLat() {return latitude;}
      long getRating() {return rating;}
      
};

// Custom comparator for sorting according to the rating
bool ratingCompare(Restaurant *a, Restaurant *b){

   return (a->getRating() > b->getRating());
}

// Main yelp class
class Yelp{
   protected:
      vector<Restaurant*> restaurants;
   public:
      Yelp();

      // Finds restaurants within a radius given current coordinates
      // Can also sort them according to their ratings
      vector<Restaurant*> findRestaurant(double lat, double lon, 
            double radius, bool sortByRating){

         int i;
         double dist; 
         vector<Restaurant*> out;

         // Get all restaurants in the database within the given radius
         for(i=0; i<restaurants.size(); i++){
            dist = calcDist(lat,lon,restaurants[i]->getLat(),
                  restaurants[i]->getLon());
            if(dist <= radius)
               out.push_back(restaurants[i]);
         }
      
         // sort them by rating
         if(sortByRating){
            sort(out.begin(), out.end(), ratingCompare);
         }

         return out;
      }
};

int main(int argc, char *argv[]){

}
