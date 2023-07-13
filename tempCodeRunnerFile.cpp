
    ReadCSV read;
    propList = read.readCSV("mudah-apartment-kl-selangor.csv");

    Property property = propList.get(0);

    cout << property.getAdsID() << endl;