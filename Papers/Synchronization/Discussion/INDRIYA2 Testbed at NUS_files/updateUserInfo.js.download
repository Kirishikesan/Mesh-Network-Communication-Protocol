function updateUserInfo(){
    if(document.getElementById("quotatxt").value.length == 0){
        document.getElementById("updateNotify").innerHTML = "Please, write a number in the quota field.";
    } else {
        if(userInfoChanged == 1) {
            //pass user info to php to update user's info on database
            var userInfo = new FormData();
            userInfo.append('userID', document.getElementById("userIDLabelFill").innerHTML);
            userInfo.append('quota', document.getElementById("quotatxt").value);
            userInfo.append('admin', document.getElementById('adminList').value);
            userInfo.append('allMotes', document.getElementById('allMotesList').value);
            userInfo.append('details', document.getElementById('userDetails').value);

            var xhr = new XMLHttpRequest();
            xhr.open('POST', 'php/updatUserInfo.php', true);
            xhr.send(userInfo);
            xhr.onload = function () {
                if (xhr.status === 200) {
                    var flag = this.responseText
                    if(flag){
                        alert("User's Information have been updated successfully.");
                        cancelUserUpdate();
                    } else{
                        document.getElementById("updateNotify").innerHTML = "An error occurred while updating user info, kindly try again later.";
                    }
                }
            };
        } else {
            document.getElementById("updateNotify").innerHTML = "Nothing has been changed to update";
        }
    }
}

function removeUser() {
    var result = confirm("Want to remove this user?");
    if (result) {
        //pass user info to php to update user's info on database
        var userInfo = new FormData();
        userInfo.append('userID', document.getElementById("userIDLabelFill").innerHTML);

        var xhr = new XMLHttpRequest();
        xhr.open('POST', 'php/removeUser.php', true);
        xhr.send(userInfo);
        xhr.onload = function () {
            if (xhr.status === 200) {
                var flag = this.responseText
                if(flag){
                    alert("User has been removed successfully.");
                    cancelUserUpdate();
                } else{
                    document.getElementById("updateNotify").innerHTML = "An error occurred while removing user, kindly try again later.";
                }
            }
        };
    }
}

function cancelUserUpdate() {
    document.getElementById("userAccountsTab").click();
}