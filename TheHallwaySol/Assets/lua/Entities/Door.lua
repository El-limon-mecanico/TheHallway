Door ={
    Active = true,
    Tag = "Door",
    Components = {"Transform","MeshRenderer", "Rigidbody", "Exit"},

    Transform = {
        Position = {0,8,0},
        Scale = {3,3,3},
        Rotation = {0,0,0}
    },

    MeshRenderer ={
        Mesh = "Door.mesh",
    },

    Rigidbody = {
        Type = "Box",
        Mass = 1,
        Trigger = true,
        Static = true,
        PositionConstrains = {1,1,1},
        RotationConstrains = {1,1,1}
    },

    Exit = {}
}