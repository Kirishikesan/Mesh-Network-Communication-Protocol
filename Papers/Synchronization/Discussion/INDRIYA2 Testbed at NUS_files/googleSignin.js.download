var userID = null;
var userName = null;
var userAdmin = 0;
var useAllMotes = 0;
var mqtt_passw = null;

function onSignIn(googleUser) {
    // Useful data for your client-side scripts:
    var profile = googleUser.getBasicProfile();
    //console.log('User signed in.');
    
    /*console.log('ID: ' + profile.getId()); // Do not send to your backend! Use an ID token instead.
    console.log('Name: ' + profile.getName());
    console.log('Image URL: ' + profile.getImageUrl());
    console.log('Email: ' + profile.getEmail()); // This is null if the 'email' scope is not present.
*/

    var id_token = googleUser.getAuthResponse().id_token;
    userID = profile.getEmail();

    var userInfo = new FormData();
    userInfo.append('email', userID);
    userInfo.append('userID', profile.getId());
    userInfo.append('id_token', id_token);

    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'php/getUser.php', true);
    xhr.send(userInfo);
    xhr.onload = function () {
        if (xhr.status === 200) {
	        var myObj = JSON.parse(this.responseText);
            userAdmin = myObj.admin;
            useAllMotes = myObj.allMotes;
    		mqtt_passw = myObj.mqtt_passw;

            //update html state after login
            document.getElementById('gSignin').style.display = 'none';
            document.getElementById('myAccountMenu').style.display = 'block';
            document.getElementById('page5').style.display = 'block';

            $('#userIDText').text("Welcome " + userID);
            userName = profile.getName();

            //go my account page if signed in
            goToByScroll("page5");

            if(userAdmin == 1){
                document.getElementById('userAccountsTab').style.display = 'block';
                document.getElementById('motesTab').style.display = 'block';
            } else{
                document.getElementById('userAccountsTab').style.display = 'none';
                document.getElementById('motesTab').style.display = 'none';
            }
                
            document.getElementById("myJobsTab").click();
        }
    };
}

function onFailure(error) {
    alert(error);
}

function signOut(){
    var auth2 = gapi.auth2.getAuthInstance();
    auth2.signOut().then(function () {
      //console.log('User signed out.');
    });
    
    auth2.disconnect();
    
    userID = null;
    userName = null;
    userAdmin = 0;
    useAllMotes = 0;
    
    //go my home page if signed out
    goToByScroll("page1");

    //update html state after login
    document.getElementById('gSignin').style.display = "block";
    document.getElementById('myAccountMenu').style.display = "none";
    document.getElementById('page5').style.display = "none";
};
