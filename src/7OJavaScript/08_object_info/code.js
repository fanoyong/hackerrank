function displayInformation() {
    var book;
     for (book in library) {
         var bookActual = library[book];
         if(bookActual.readingStatus) {
             console.log("Already read \'" + bookActual["title"] + "\' by " + bookActual["author"] + ".");
         } else {
             console.log("You still need to read \'" + bookActual["title"] + "\' by " + bookActual["author"] + ".")
         }
     }
} 

// tail starts here
var library = [ 
    {
        title: 'Bill Gates',
        author: 'The Road Ahead',
        readingStatus: true
    },
    {
        title: 'Steve Jobs',
        author: 'Walter Isaacson',
        readingStatus: true
    },
    {
        title: 'Mockingjay: The Final Book of The Hunger Games',
        author: 'Suzanne Collins',
        readingStatus: false
    }
];

displayInformation();
