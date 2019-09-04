void addRoman(int num, int scalar ,string* svec);

class Solution {
public:
    string intToRoman(int num) {
        int scalar=0;
        string svec;
            
        while(num > 0)
        {
            int tmp = num%10;
            
            if(tmp > 0)
                addRoman(tmp, scalar, &svec);
            
            scalar++;
            num/=10;
        }
        
        return svec;
    }
};


void addRoman(int num, int scalar ,string* svec)
{
    map<int, char> mapDigit;
    if(scalar == 0)
    {
        mapDigit[1] = 'I';
        mapDigit[5] = 'V';
        mapDigit[10] = 'X';
    }
    else if(scalar == 1)
    {
        mapDigit[1] = 'X';
        mapDigit[5] = 'L';
        mapDigit[10] = 'C';
    }
    else if(scalar == 2)
    {
        mapDigit[1] = 'C';
        mapDigit[5] = 'D';
        mapDigit[10] = 'M'; 
    }
    else
    {
        mapDigit[1] = 'M';
    }

    string::iterator it = svec->begin();
    if(5 > num)
    {
        
        if(num == 4)
        {
            svec->insert(it,mapDigit[5]);
            svec->insert(it,mapDigit[1]);
        }
        else
            svec->insert(it, num, mapDigit[1]);
        
    }
    else //(9> num && num >=5)
    {
        if(num == 9)
        {
            svec->insert(it,mapDigit[10]);
            svec->insert(it,mapDigit[1]);
        }
        else
        {
            svec->insert(it, num-5, mapDigit[1]);
            svec->insert(it, mapDigit[5]);
        }

    }
}
