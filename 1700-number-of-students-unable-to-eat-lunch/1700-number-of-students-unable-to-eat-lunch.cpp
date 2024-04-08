// class Solution {
// public:
//     int countStudents(vector<int>& students, vector<int>& sandwiches) {
//     queue<int> sandw;
//     queue<int> stude;

//     for(int i = 0; i< students.size() ; i++){
//         sandw.push(sandwiches[i]);
//         stude.push(students[i]);
//     } 

//     for(int i =0; i< sandw.size() ; i++){

//     }
//     }
// };

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> students_type = {0,0};
        for(int i: students) ++students_type[i];
        for(int i: sandwiches)
            if(!students_type[i]--) return students_type[1-i];
        return 0;
    }
};