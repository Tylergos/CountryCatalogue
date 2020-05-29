from Country import *
from CountryCatalogue import *


def tstFindCountry(countryCatalog):
    print()
    print("Looking up country")
    cntry = input("-- Enter name of country: ")
    cntry = cntry.strip()
    cntryObj = countryCatalog.findCountry(cntry)
    if cntryObj is None:
        print("-- Country not found in list")
    else:
        print(cntryObj)

def tstSetPopulationOfCountry(countryCatalog):
    print()
    print("Setting population of country")
    itemFound = False
    cntry = input("-- Enter name of country: ")
    cntry = cntry.strip()
    cPop = input("  --  Enter new population: ")
    cPop = cPop.strip()
    cPop = int(cPop.replace(",",""))
    itemFound = countryCatalog.setPopulationOfSelectedCountry(cntry,cPop)
    if not itemFound:
        print("  Country " + cntry + " is not in the current list")

def tstAddCountry(countryCatalog):
    print()
    cntry = input("-- Enter name of country to add: ")
    cntry = cntry.strip()
    thePop = input("      Enter the population: ")
    thePop = thePop.strip()
    cPop = int(thePop.replace(",",""))
    theSz = input("      Enter the size(area): ")
    theSz = theSz.strip()
    cSz = float(theSz.replace(",",""))
    theCont = input("      Enter the continent: ")
    theCont = theCont.strip()
    itemFound = countryCatalog.addCountry(cntry,cPop,cSz,theCont)
    if not itemFound:
        print("  Country " + cntry + " is already in the current list")

def tstDeleteCountry(countryCatalog):
    print()
    cntry = input("-- Enter name of country to delete: ")
    cntry = cntry.strip()
    countryCatalog.deleteCountry(cntry)

def tstFilterCountriesByContinent(countryCatalog,theCont):
    lst = countryCatalog.filterCountriesByContinent(theCont)
    if len(lst) > 0:
        print()
        print("Countries in "+theCont+" are:")
        for cobj in lst:
            print(cobj)

def tstFindMostPopulousContinent(countryCatalog):
    rName, rPop = countryCatalog.findMostPopulousContinent()
    print()
    print("The most populous continent is "+ rName + " with a population of " + str(rPop))

def tstFindCountryWithLargestPop(countryCatalog):
    rslt = countryCatalog.findCountryWithLargestPop()
    print()
    print("The country with the largest population is " + rslt.getName())

def tstFindCountryWithSmallestArea(countryCatalog):
    rslt = countryCatalog.findCountryWithSmallestArea()
    print()
    print("The country with the smallest area is " + rslt.getName())

def tstFilterCountriesByPopDensity(countryCatalog):
    print()
    lb = input("-- Enter the lower bound for population density: ")
    lb = float(lb.strip())
    ub = input("-- Enter the upper bound for population density: ")
    ub = float(ub.strip())
    rlst = countryCatalog.filterCountriesByPopDensity(lb,ub)
    if len(rlst) == 0:
        print("  No countries with density in that range found.")
    else:
        print("  Countries with density in this range are:")
        for ac in rlst:
            print(ac.getName() + ", " + "density = "+ str(ac.getPopDensity()))

def tstSaveCountryCatalogue(cc,fname):
    print()
    print("Saving Country Catalogue")
    nitems = cc.saveCountryCatalogue(fname)
    print(" "+str(nitems)+" items written to file "+fname)


def main():
    cc = CountryCatalogue('continent.txt','country.txt')
    # print initial catalogue
    cc.printCountryCatalogue()
    # find a country
    tstFindCountry(cc)
    # add a country, delete a country, print the new catalogue and find a country in the new catalogue
    tstAddCountry(cc)
    tstDeleteCountry(cc)
    print()
    cc.printCountryCatalogue()
    tstFindCountry(cc)
    # set the area and population
    tstSetPopulationOfCountry(cc)
    # print various parts of the catalogue
    tstFilterCountriesByContinent(cc,"Europe")
    #test the largest pop and smallest area
    tstFindCountryWithLargestPop(cc)
    tstFindCountryWithSmallestArea(cc)
    # test filters
    tstFilterCountriesByPopDensity(cc)
    tstFindMostPopulousContinent(cc)
    # print final catalogue and then output it to a file
    print()
    cc.printCountryCatalogue()
    tstSaveCountryCatalogue(cc,'output.txt')

main()
